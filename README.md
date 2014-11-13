DAS - Distributed Address Space
---------------------------------

The address space is uniformly distributed over a set of N nodes.
An application can transparently access any memory address.

Accesses in remote memory are trapped and memory is fetched to local access.
Traps are served by DUNE and data is fetched with RDMA. 


        ----------------                       ---------------- 
        |  Application |                       |  Application | 
        ----------------                       ---------------- 
        |     DUNE     |                       |     DUNE     | 
        ----------------                       ---------------- 
        |      OS      |                       |      OS      | 
        ----------------       Transport*      ---------------- 
        | Melanox Card |    <------------->    | Melanox Card | 
        ----------------                       ----------------


*Transport can be any of:
1) RDMA
2) IB Verbs
3) TCP
4) TCP with bypass

