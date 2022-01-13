# client_server_3
This project shows an example of client–server model using Qt framework (events and sockets). Specifically:  
1. the server starts listening, it starts a timer to send a message every 5 s and waits for a connection (busy-waiting instead of event)
2. the client starts and connects to the server
3. the server sends two separate messages and waits for a response (busy-waiting instead of event)
4. the client receives the two messages and replies
5. the server receives the reply and sends a message every 5 s.
