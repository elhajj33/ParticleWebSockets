***********************************
***   Particle WebSocket Demo   ***
***********************************
This demo is based on Arduino WebSockets by Markus Sattler found here:
https://github.com/Links2004/arduinoWebSockets

Author: Ali Elhajj
Last Revised: 5/12/2017

BUILDING:
This project builds and runs without issues using the Particle Dev IDE on mac.
I haven't tested it elsewhere, but I don't suspect you will have any issues.

RUNNING:
  1.  You will want to use Google Chrome for testing as the output of the test
      will be output to the console.
  2.  Compile and flash your Particle
  3.  Check your particle log for your Local IP address
  4.  Modify line 6 of the SocketTest.html file under the "examples" folder:
        var sock = new WebSocket('ws://192.168.1.115:81/', ['arduino']);
  5.  Be sure to only modify your IP and NOT the port.  The example uses port 81

That's all you should need to do. Javascript will send 10 messages to Particle
that will then be echoed back. The socket will then close after the 10th message

DISCLAIMERS:
This is an example. While it works, it's up to you to test it and take full
responsibility for whatever you end up doing with it!  I'll try to help, but like everyone else,
my time is pretty limited.  

---
Copyright (c) 2015 Ali Elhajj. All rights reserved.
This code is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
