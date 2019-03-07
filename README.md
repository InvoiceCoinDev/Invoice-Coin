Invoice-Coin [IVC] integration/staging tree
===========================================

https://invoicecoin.us/

What is the Invoice-Coin [IVC] Blockchain?
------------------------------------------
*TODO: Update documentation regarding implemented tech as this section is out of date and much progress and upgrades have been made to mentioned sections...*

### Overview
The InvoiceCoin application platform, when completed, will be a free downloadable app that will 
allow the user real time crypto currency conversion billing for private use. 
The biller and payer will be able to agree on currency value in real time by selecting options such 
as current market value or pre-determined value. 

With the use of the InvoiceCoin app the crypto community can use viable currency of choice to pay or 
get paid for value and services rendered. This is the next step in eliminating costly 
traditional billing transactions and maintaining the privacy and viability of crypto currency transactions.

### Blockchain Technology
The Invoice-Coin [IVC] Blockchain is an experimental smart contract platform protocol that enables 
instant payments to anyone, anywhere in the world in a private, secure manner. 
Invoice-Coin [IVC] uses peer-to-peer blockchain technology developed by Invoice-Coin to operate
with no central authority: managing transactions, execution of contracts, and 
issuing money are carried out collectively by the network. Invoice-Coin [IVC] is the name of 
open source software which enables the use of this protocol.

### Custom Difficulty Retarget Algorithm “VRX”
VRX is designed from the ground up to integrate properly with the Velocity parameter enforcement system to ensure users no longer receive orphan blocks.

### Velocity Block Constraint System
Ensuring Insane stays as secure and robust as possible the CryptoCoderz team have implemented what's known as the Velocity block constraint system. This system acts as third and final check for both mined and peer-accepted blocks ensuring that all parameters are strictly enforced.

### Wish (bmw512) Proof-of-Work Algorithm
Wish or bmw512 hashing algorithm is utilized for the Proof-of-Work function and also replaces much of the underlying codebase hashing functions as well that normally are SHA256. By doing so this codebase is able to be both exponentially lighter and more secure in comparison to reference implementations.

Specifications and General info
------------------
Invoice-Coin uses 

	libsecp256k1,
	libgmp,
	Boost1.68, OR Boost1.58,  
	Openssl1.02r,
	Berkeley DB 6.2.32,
	QT5.12.1,
	to compile


General Specs

	Block Spacing: 3 Minutes
	Stake Minimum Age: 25 Confirmations (PoS-v3) | 30 Minutes (PoS-v2)
	Port: 10877
	RPC Port: 10879


BUILD LINUX
-----------
### Compiling Invoice-Coin daemon on Ubunutu 18.04 LTS Bionic
### Note: guide should be compatible with other Ubuntu versions from 14.04+

### Become poweruser
```
sudo -i
```
### CREATE SWAP FILE FOR DAEMON BUILD (if system has less than 2GB of RAM)
```
cd ~; sudo fallocate -l 3G /swapfile; ls -lh /swapfile; sudo chmod 600 /swapfile; ls -lh /swapfile; sudo mkswap /swapfile; sudo swapon /swapfile; sudo swapon --show; sudo cp /etc/fstab /etc/fstab.bak; echo '/swapfile none swap sw 0 0' | sudo tee -a /etc/fstab
```

### Dependencies install
```
cd ~; sudo apt-get install -y ntp git build-essential libssl-dev libdb-dev libdb++-dev libboost-all-dev libqrencode-dev libcurl4-openssl-dev curl libzip-dev; apt-get update -y; apt-get install -y git make automake build-essential libboost-all-dev; apt-get install -y yasm binutils libcurl4-openssl-dev openssl libssl-dev; sudo apt-get install -y libgmp-dev; sudo apt-get install -y libtool;
```

### Dependencies build and link
```
cd ~; wget http://download.oracle.com/berkeley-db/db-6.2.32.NC.tar.gz; tar zxf db-6.2.32.NC.tar.gz; cd db-6.2.32.NC/build_unix; ../dist/configure --enable-cxx; make; sudo make install; sudo ln -s /usr/local/BerkeleyDB.6.2/lib/libdb-6.2.so /usr/lib/libdb-6.2.so; sudo ln -s /usr/local/BerkeleyDB.6.2/lib/libdb_cxx-6.2.so /usr/lib/libdb_cxx-6.2.so; export BDB_INCLUDE_PATH="/usr/local/BerkeleyDB.6.2/include"; export BDB_LIB_PATH="/usr/local/BerkeleyDB.6.2/lib"
```

### GitHub pull (Source Download)
```
cd ~; git clone https://github.com/CryptoCoderz/Invoice-Coin
```

### Build Invoice-Coin daemon
```
cd ~; cd ~/Invoice-Coin/src; chmod a+x obj; chmod a+x leveldb/build_detect_platform; chmod a+x secp256k1; chmod a+x leveldb; chmod a+x ~/Invoice-Coin/src; chmod a+x ~/Invoice-Coin; make -f makefile.unix USE_UPNP=-; cd ~; cp -r ~/Invoice-Coin/src/Invoice-Coind /usr/local/bin/Invoice-Coind;
```

### Create config file for daemon
```
cd ~; sudo ufw allow 10877/tcp; sudo ufw allow 10879/tcp; sudo ufw allow 22/tcp; sudo mkdir ~/.IVC; cat << "CONFIG" >> ~/.IVC/Invoice-Coin.conf
listen=1
server=1
daemon=1
testnet=0
rpcuser=IVCrpcuser
rpcpassword=SomeCrazyVeryVerySecurePasswordHere
rpcport=10879
port=10877
rpcconnect=127.0.0.1
rpcallowip=127.0.0.1
addnode=178.128.242.233
addnode=142.93.108.48
addnode=159.203.240.221
addnode=188.166.109.87
CONFIG
chmod 700 ~/.IVC/Invoice-Coin.conf; chmod 700 ~/.IVC; ls -la ~/.IVC
```

### Run Invoice-Coin daemon
```
cd ~; Invoice-Coind; Invoice-Coind getinfo
```

### Troubleshooting
### for basic troubleshooting run the following commands when compiling:
### this is for minupnpc errors compiling

```
make clean -f makefile.unix USE_UPNP=-
make -f makefile.unix USE_UPNP=-
```
### Updating daemon in bin directory
```
cd ~; cp -r ~/Invoice-Coin/src/Invoice-Coind /usr/local/bin
```

License
-------

Invoice-Coin [IVC] is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/CryptoCoderz/IVC/tags) are created
regularly to indicate new official, stable release versions of Invoice-Coin [IVC].

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

The developer [mailing list](https://lists.linuxfoundation.org/mailman/listinfo/bitcoin-dev)
should be used to discuss complicated or controversial changes before working
on a patch set.

Developer Discord can be found at:

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](/doc/unit-tests.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`

There are also [regression and integration tests](/qa) of the RPC interface, written
in Python, that are run automatically on the build server.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.