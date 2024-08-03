#include "server.hpp"

#include <pistache/endpoint.h>

using namespace Pistache;

namespace Arrp_Web {

Options & options()
{
    static Options options;
    return options;
}

class Play_Handler : public Http::Handler
{
    Play_Handler();

    int next_id();
    virtual void onRequest(const Http::Request&, Http::ResponseWriter) override;

    mutex d_mutex;
    int d_max_ids = 10;
    int d_next_id = 0;
};


Play_Handler::Play_Handler()
{
    d_max_ids = options().max_log_count;
}

int Play_Handler::next_id()
{
    lock_guard<mutex> guard(d_mutex);

    int id = d_next_id;

    d_next_id = (d_next_id + 1) % d_max_ids;
}

void Play_Handler::onRequest(const Http::Request& request, Http::ResponseWriter response)
{


}



Server::Server()
{

}

void Server::serve()
{
    Net::Address addr(Net::Ipv4::any(), Net::Port(options().port));

    auto opts = Http::Endpoint::options().threads(1);

    Http::Endpoint server(addr);
    server.init(opts);
    server.setHandler(std::make_shared<Play_Handler>());
    server.serve();
}


}
