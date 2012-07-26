#ifndef __LIBED2K_SESSION_SETTINGS__
#define __LIBED2K_SESSION_SETTINGS__

namespace libed2k
{

    class session_settings
    {
    public:
        typedef std::vector<std::pair<std::string, bool> >  fd_list;

        session_settings():
            server_timeout(220),
            peer_timeout(120),
            peer_connect_timeout(7),
            block_request_timeout(10),
            allow_multiple_connections_per_ip(false),
            recv_socket_buffer_size(0),
            send_socket_buffer_size(0),
            server_port(4661),
            listen_port(4662),
            client_name("libed2k"),
            server_keep_alive_timeout(200),
            server_reconnect_timeout(5),
            max_peerlist_size(4000),
            download_rate_limit(-1),
            upload_rate_limit(-1),
            m_version(0x3c),
            m_max_announces_per_call(100),
            m_announce_timeout(-1),
            m_show_shared_catalogs(true),
            m_show_shared_files(true),
            user_agent(md4_hash::emule)
        {
        }

        // the number of seconds to wait for any activity on
        // the server wire before closing the connection due
        // to time out.
        int server_timeout;

        // the number of seconds to wait for any activity on
        // the peer wire before closing the connection due
        // to time out.
        int peer_timeout;

        // this is the timeout for a connection attempt. If
        // the connect does not succeed within this time, the
        // connection is dropped. The time is specified in seconds.
        int peer_connect_timeout;

        // the number of seconds to wait for block request.
        int block_request_timeout;

        // false to not allow multiple connections from the same
        // IP address. true will allow it.
        bool allow_multiple_connections_per_ip;

        // sets the socket send and receive buffer sizes
        // 0 means OS default
        int recv_socket_buffer_size;
        int send_socket_buffer_size;

        // ed2k server hostname
        std::string server_hostname;
        // ed2k server port
        int server_port;
        // ed2k peer port for incoming peer connections
        int listen_port;
        // ed2k client name
        std::string client_name;
        int server_keep_alive_timeout;
        // reconnect to server after fail, -1 - do nothing
        int server_reconnect_timeout;

        // the max number of peers in the peer list
        // per transfer. This is the peers we know
        // about, not necessarily connected to.
        int max_peerlist_size;

        /**
          * session rate limits
          * -1 unlimits
         */
        int download_rate_limit;
        int upload_rate_limit;
        unsigned short m_version;
        unsigned short m_max_announces_per_call;

        /**
          * announce timeout in seconds
          * -1 - announces off
         */
        int m_announce_timeout;
        bool m_show_shared_catalogs;    //!< show shared catalogs to client
        bool m_show_shared_files;       //!< show shared files to client
        md4_hash user_agent;            //!< ed2k client hash - user agent information

        //!< known.met file
        std::string m_known_file;

        //!< users files and directories
        //!< second parameter true for recursive search and false otherwise
        fd_list m_fd_list;

        /**
          * root directory for auto-creating collections
          * collection will create when we share some folder
         */
        std::string m_collections_directory;

    };

}

#endif
