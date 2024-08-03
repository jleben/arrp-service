#pragma once

namespace Arrp_Web {

class Options
{
public:
    int port = 8000;
    string data_path;
    int max_log_count = 100;
};

Options & options();

class Server
{
public:
    Server();
    void serve();
};

}
