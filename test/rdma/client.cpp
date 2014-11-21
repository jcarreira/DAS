
#include <endian.h>
#include <infiniband/verbs.h>

/* structure of system resources */
struct resources
{
    struct ibv_device_attr device_attr; /* Device attributes */
    struct ibv_port_attr port_attr;       /* IB port attributes */
    struct cm_con_data_t remote_props;    /* values to connect to remote side */
    struct ibv_context *ib_ctx;   /* device handle */
    struct ibv_pd *pd;            /* PD handle */
    struct ibv_cq *cq;            /* CQ handle */
    struct ibv_qp *qp;            /* QP handle */
    struct ibv_mr *mr;            /* MR handle for buf */
    char *buf;                    /* memory buffer pointer, used for RDMA and send
                                     ops */
    int sock;                     /* TCP socket file descriptor */
};


static void
resources_init (struct resources *res)
{
    memset (res, 0, sizeof *res);
    res->sock = -1;
}

/*int resources_create(struct resources *res) {
    // connect to server

    // get device list
    dev_list = ibv_get_device_list (&num_devices);

    // find first IB device we can use
    for (i = 0; i < num_devices; i++) {
        if (!config.dev_name) {
            config.dev_name = strdup (ibv_get_device_name (dev_list[i]));
            fprintf (stdout, "device not specified, using first one found: %s\n", config.dev_name);
        }
        if (!strcmp (ibv_get_device_name (dev_list[i]), config.dev_name)) {
            ib_dev = dev_list[i];
            break;
        }
    }

    assert(ib_dev);

    // open device
    res->ib_ctx = ibv_open_device (ib_dev);
    assert(res->ib_ctx);

    ibv_free_device_list (dev_list);
    dev_list = NULL;
    ib_dev = NULL;

    assert(
      ibv_query_port (res->ib_ctx, 
          config.ib_port, &res->port_attr) == 0);

    // allocate protection domain
    res->pd = ibv_alloc_pd (res->ib_ctx);
    assert(res->pd);

    // create completion queue with size 1
    cq_size = 1;
    res->cq = 
        ibv_create_cq (res->ib_ctx, cq_size, NULL, NULL, 0);

    assert(res->cq);
    
    
    size = MSG_SIZE;
    res->buf = (char *) malloc (size);
    memset (res->buf, 0, size);
    mr_flags = IBV_ACCESS_LOCAL_WRITE | IBV_ACCESS_REMOTE_READ |
        IBV_ACCESS_REMOTE_WRITE;
    res->mr = ibv_reg_mr (res->pd, res->buf, size, mr_flags);
    assert(res->mr);

    // create the queue pair
    memset (&qp_init_attr, 0, sizeof (qp_init_attr));
    qp_init_attr.qp_type = IBV_QPT_RC;
    qp_init_attr.sq_sig_all = 1;
    qp_init_attr.send_cq = res->cq;
    qp_init_attr.recv_cq = res->cq;
    qp_init_attr.cap.max_send_wr = 1;
    qp_init_attr.cap.max_recv_wr = 1;
    qp_init_attr.cap.max_send_sge = 1;
    qp_init_attr.cap.max_recv_sge = 1;
    res->qp = ibv_create_qp (res->pd, &qp_init_attr);
    assert(res->qp);
}*/

static int
connect_qp (struct resources *res)
{

    return 0;
}

static int
resources_destroy (struct resources *res) {
    int rc = 0;
    if (res->qp)
        assert (ibv_destroy_qp (res->qp) == 0);
    if (res->mr)
        assert(ibv_dereg_mr (res->mr) == 0);
    if (res->buf)
        free (res->buf);
    if (res->cq)
        assert (ibv_destroy_cq (res->cq) == 0);
    if (res->pd)
        assert (ibv_dealloc_pd (res->pd) == 0);
    if (res->ib_ctx)
        assert (ibv_close_device (res->ib_ctx) == 0);
    if (res->sock >= 0)
        assert (close (res->sock) == 0);
    return 0;
}

int main() {
    struct resources res;
    resources_init(&res);

    //assert( resources_create() == 0);

    /*assert( connect_qp(&res) == 0);

    assert(
            sock_sync_data(res.sock, 1, "R", &temp_char)
            == 0);
        
    assert( post_send (&res, IBV_WR_RDMA_READ) == 0);

    assert( poll_completion (&res) == 0);

    assert( post_send (&res, IBV_WR_RDMA_WRITE) == 0);

    assert( poll_completion (&res) == 0);

    assert( 
        sock_sync_data (res.sock, 1, "W", &temp_char) == 0);
*/
    resources_destroy (&res);

    return 0;

}
