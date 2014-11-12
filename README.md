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
        ----------------        RDMA           ---------------- 
        | Melanox Card |    <------------->    | Melanox Card | 
        ----------------                       ----------------




