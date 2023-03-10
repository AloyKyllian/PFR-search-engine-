#include <microhttpd.h>
#include <stdio.h>
#include "test.h"

#define PORT 8888

int test_handler(void *arg, struct MHD_Connection *connection,
  const char *url, const char *method, const char *version,
  const char *upload_data, size_t *upload_data_size, void **ptr)
{
  const char *data = "hello";

  struct MHD_Response *response;
  int ret;

  test();

  response = MHD_create_response_from_buffer(strlen(data), (void*)data, MHD_RESPMEM_PERSISTENT);
  ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
  MHD_destroy_response(response);

  return ret;
}

int main()
{
  struct MHD_Daemon *daemon;

  daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, PORT, NULL, NULL,
                            &test_handler, NULL, MHD_OPTION_END);
  if (NULL == daemon) {
    return 1;
  }

  getchar();

  MHD_stop_daemon(daemon);

  return 0;
}