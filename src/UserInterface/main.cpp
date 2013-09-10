/*
 * Copyright 2012-2013 Patrick Kramer, Vincent Wassenaar
 *
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "javaenvironment.h"

#include "jace/proxy/types/JLong.h"
#include "jace/proxy/java/lang/System.h"

using namespace jace::proxy::java::lang;
using namespace jace::proxy::types::JLong;

int main(int, char*[]) {
  JavaEnvironment env;
  try {
    env.start();
  } catch (std::runtime_error& err) {
    qDebug() << "A runtime error occurred:" << err.what();
    return EXIT_FAILURE;
  }

  JLong millis = System::currentTimeMillis(); // get a long from the Java environment
  qint64 longMillis = static_cast<qint64> (millis.getLong()); // Java's long is a 64-bit integer (Qt defines it as qint64)

  qDebug() << "Java System millisecond time: " << longMillis;

  return EXIT_SUCCESS;
}
