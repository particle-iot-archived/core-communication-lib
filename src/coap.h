/**
  ******************************************************************************
  * @file    coap.h
  * @authors  Zachary Crockett
  * @version V1.0.0
  * @date    15-Nov-2013
  * @brief   COAP
  ******************************************************************************
  Copyright (c) 2013 Spark Labs, Inc.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation, either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, see <http://www.gnu.org/licenses/>.
  ******************************************************************************
  */

#include <string.h>

namespace CoAPMessageType {
  enum Enum {
    HELLO,
    DESCRIBE,
    FUNCTION_CALL,
    VARIABLE_REQUEST,
    SAVE_BEGIN,
    UPDATE_BEGIN,
    UPDATE_DONE,
    CHUNK,
    EVENT,
    KEY_CHANGE,
    SIGNAL_START,
    SIGNAL_STOP,
    TIME,
    EMPTY_ACK,
    PING,
    ERROR
  };
}

namespace CoAPCode {
  enum Enum {
    GET,
    POST,
    PUT,
    EMPTY,
    CONTENT,
    ERROR
  };
}

namespace CoAPType {
  enum Enum {
    CON,
    NON,
    ACK,
    RESET
  };
}

class CoAP
{
  public:
    static CoAPCode::Enum code(const unsigned char *message);
    static CoAPType::Enum type(const unsigned char *message);
    static size_t option_decode(unsigned char **option);
};
