#include "mongoose.h"

static const char *url = "http://www.google.com";
static int exit_flag = 0;

static void ev_handler(struct mg_connection *c, int ev, void *p) {
    if (ev == MG_EV_HTTP_REPLY) {
    struct http_message *hm = (struct http_message *)p;
    c->flags |= MG_F_CLOSE_IMMEDIATELY;
    fwrite(hm->message.p, 1, (int)hm->message.len, stdout);
    putchar('\n');
    exit_flag = 1;
    } else if (ev == MG_EV_CLOSE) {
    exit_flag = 1;
    };
}

int main(void) {
    struct mg_mgr mgr;

    mg_mgr_init(&mgr, NULL);
    mg_connect_http(&mgr, ev_handler, url, NULL, NULL);

    while (exit_flag == 0) {
        mg_mgr_poll(&mgr, 1000);
    }
    mg_mgr_free(&mgr);

    return 0;
}
