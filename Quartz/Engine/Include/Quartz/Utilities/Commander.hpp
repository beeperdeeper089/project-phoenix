// Copyright 2019 Genten Studios
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors
// may be used to endorse or promote products derived from this software without
// specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#pragma once

#include <string>

namespace qz
{
	namespace utils
	{
        /**
         * @brief The Commander handles comand line functions while the server is running. A loop will watch for commands from the terminal while the server runs but the clients can also send commands.
         * 
         */
        class Commander{
            private:
            std::string m_command[100];
            std::string m_permission[100];
            int (*m_function[100])();
            int i;
            //TODO: These need to be dynamicaly sized

            public:

            Commander();
            ~Commander();

            /**
             * @brief Registers a command in the command registry
             * 
             * @param command The keyword for calling the command
             * @param permission What permission is required to run this command
             */
            void reg(std::string command, std::string permission, int (*f)());

            /**
             * @brief Calls a command 
             * 
             * @param command The keyword for calling the command.
             */
            int run(std::string command);

            /**
             * @brief Lists available commands 
             * 
             * 
             */
            std::string list();
        };

    };
}