/*
 * casocklib - An asynchronous communication library for C++
 * ---------------------------------------------------------
 * Copyright (C) 2010 Leandro Costa
 *
 * This file is part of casocklib.
 *
 * casocklib is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * casocklib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with casocklib. If not, see <http://www.gnu.org/licenses/>.
 */

/*!
 * \file casock/proactor/asio/server/SocketServer.h
 * \brief [brief description]
 * \author Leandro Costa
 * \date 2010
 *
 * $LastChangedDate$
 * $LastChangedBy$
 * $Revision$
 */

#ifndef __CASOCKLIB__CASOCK_PROACTOR_ASIO_SERVER__SOCKET_SERVER_H_
#define __CASOCKLIB__CASOCK_PROACTOR_ASIO_SERVER__SOCKET_SERVER_H_

#include <set>
#include <asio.hpp>

namespace casock {
  namespace proactor {
    namespace asio {
      namespace base {
        class AsyncProcessor;
      }

      namespace server {
        class SocketSession;

        class SocketServer
        {
          public:
            SocketServer (casock::proactor::asio::base::AsyncProcessor& rAsyncProcessor, const unsigned short& port);
            virtual ~SocketServer ();

          private:
            void asyncAccept ();
            void handle_accept (SocketSession* pSession, const ::asio::error_code& error);

          protected:
            virtual SocketSession* buildSession (casock::proactor::asio::base::AsyncProcessor& rAsyncProcessor) = 0;

          public:
            void start ();
            void close ();
            void closeAcceptor ();
            void removeSession (SocketSession* pSocketSession);

          private:
            casock::proactor::asio::base::AsyncProcessor& mrAsyncProcessor;
            ::asio::ip::tcp::acceptor m_acceptor;

            std::set<SocketSession*> mSessionSet;
        };
      }
    }
  }
}

#endif // __CASOCKLIB__CASOCK_PROACTOR_ASIO_SERVER__SOCKET_SERVER_H_
