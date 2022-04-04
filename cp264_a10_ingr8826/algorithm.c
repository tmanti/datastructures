// your code signature

#include <stdio.h>
#include <stdlib.h> 
#include "heap.h"
#include "algorithm.h"

EDGELIST *mst_prim(GRAPH *g, int start) {
    if (g == NULL) return NULL;
    int i, heapindex, u, n = g->order, T[n], parent[n];
    for (i = 0; i < n; i++) T[i] = 0; // T[] represents nodes in current tree
    for (i = 0; i < n; i++) parent[i] = -1; // parent[i] represents parent of i

    HNODE hn; // temp hash note variable
    HEAP *h = new_heap(4); // heap for finding minimum weight edge

    T[start] = 1;
    ADJNODE *temp = g->nodes[start]->neighbor;
    while (temp) {
        hn.key = temp->weight;
        hn.data = temp->nid;
        insert(h, hn);
        parent[temp->nid] = start;
        temp = temp->next;
    }

    // create EDGELIST object to hold MST
    EDGELIST *mst = new_edgelist();
    while (h->size > 0) {
        hn = extract_min(h); // get the minimum node, time
        i = hn.data;
        T[i] = 1; // add i to current tree
        add_edge_end(mst, parent[i], i, hn.key); // add to MST
        // update the keys of neighbors of the newly added node
        temp = g->nodes[i]->neighbor;
        while (temp) {
            heapindex = find_data_index(h, temp->nid);
            if (heapindex >= 0) {
                if (T[temp->nid] == 0 && temp->weight < h->hna[heapindex].key) {
                    change_key(h, heapindex, temp->weight);
                    T[temp->nid] = i;
                }
            } else {
                if (T[temp->nid] == 0) {
                    hn.key = temp->weight;
                    hn.data = temp->nid;
                    insert(h, hn);
                    parent[temp->nid] = i;
                }
            }
            temp = temp->next;
        }
    }
    return mst;
}

EDGELIST *spt_dijkstra(GRAPH *g, int start) {
    if (!g) return NULL;
    EDGELIST *spt = new_edgelist();
    int i, heapindex, u, n = g->order;
    int T[n], parent[n], label[n];
    HNODE hn;
    for (i = 0; i < n; i++) { T[i] = 0; label[i] = 9999; }
    HEAP *h = new_heap(4);
    label[start] = 0;
    T[start] = 1;

    u = start;
    
    while((g->order-1) - spt->size != 0){
        ADJNODE *v = g->nodes[u]->neighbor;
        while(v){
            if(label[u]+v->weight < label[v->nid]){
                label[v->nid] = label[u]+v->weight;
                parent[v->nid] = u;
                hn.key = v->weight + label[u];
                hn.data = v->nid;
                insert(h, hn);
            }
            v = v->next;
        }

        if(h->size != 0){
            hn = extract_min(h);
            /*printf("YEP:%d\n", hn.data);
            printf("L:%d\n", label[hn.data]);
            printf("S:%d\n", g->order - spt->size);*/
            if(label[hn.data] != 9999){
                u = hn.data;
                T[u] = 1;
                label[u] = hn.key;
                add_edge_end(spt, parent[u], u, label[u]-label[parent[u]]);
                //printf("ADDED: %d %d %d\n",  parent[u], u, label[u]-label[parent[u]]);
            }
        }
    }

    return spt;
}

EDGELIST *sp_dijkstra(GRAPH *g, int start, int end) {
   if (!g) return NULL;
    EDGELIST *spt = new_edgelist();
    int i, heapindex, u, n = g->order;
    int T[n], parent[n], label[n];
    HNODE hn;
    for (i = 0; i < n; i++) { T[i] = 0; label[i] = 9999; }
    HEAP *h = new_heap(4);
    label[start] = 0;
    T[start] = 1;

    u = start;
    
    while((g->order-1) - spt->size != 0){
        ADJNODE *v = g->nodes[u]->neighbor;
        while(v){
            if(label[u]+v->weight < label[v->nid]){
                label[v->nid] = label[u]+v->weight;
                parent[v->nid] = u;
                hn.key = v->weight + label[u];
                hn.data = v->nid;
                insert(h, hn);
            }
            v = v->next;
        }

        if(h->size != 0){
            hn = extract_min(h);
            /*printf("YEP:%d\n", hn.data);
            printf("L:%d\n", label[hn.data]);
            printf("S:%d\n", g->order - spt->size);*/
            if(label[hn.data] != 9999){
                u = hn.data;
                T[u] = 1;
                label[u] = hn.key;
                add_edge_end(spt, parent[u], u, label[u]-label[parent[u]]);
                //printf("ADDED: %d %d %d\n",  parent[u], u, label[u]-label[parent[u]]);
            }
        }
    }
    EDGELIST *sp = new_edgelist();
    i = end;
    while (1) {
        if (i == start) break;
        add_edge_start(sp, parent[i], i, label[i]-label[parent[i]]);
        i = parent[i];
    }
    return sp;
}