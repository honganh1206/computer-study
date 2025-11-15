## Client/Model

Divide an application's responsibilities among two actors: Client processes and server processes. The client sends requests to the server process, which either satisfies those requests or reports an error.

## Peer-to-peer

In this model, peer processes self-organize the application in a structure in which *each process takes on roughly the same responsibilities with other processes*

An example is the BitTorrent file sharing protocol: Each peer repeatedly exchanges parts of a file with others until they've all received the entire file.

However, P2P applications require complex coordination algorithms, so it's challenging to build and test.