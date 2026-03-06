# c-http-server

A minimal multi-threaded HTTP server written in **C**.

This project demonstrates fundamental backend and systems programming concepts including socket networking, HTTP protocol basics, and concurrent request handling using POSIX threads.

---

## Features

- Multi-threaded server (pthread)
- Static file serving
- Basic API routing
- Logging system
- Content-Type detection
- Automatic `/` → `index.html`
- 404 error handling

---

## Project Structure


```
c-http-server/
│
├── src/
│ ├── main.c
│ ├── server.c
│ ├── request.c
│ ├── response.c
│ ├── router.c
│ └── logger.c
│
├── include/
│ ├── server.h
│ ├── request.h
│ ├── response.h
│ ├── router.h
│ └── logger.h
│
├── public/
│ └── index.html
│
├── logs/
│ └── server.log
│
├── build/
├── Makefile
└── README.md

```

---

## Build


```
make
```

---

## Run


```
./build/server
```

or

```
make run
```


Server will start on:


```
http://localhost:8080
```


---

## Example Requests

Home page:


```
curl localhost:8080
```


API routes:


```
curl localhost:8080/api/hello
curl localhost:8080/api/time
```


---

## Example Log Output


[2026-03-06 19:12:31] GET / 200
[2026-03-06 19:12:34] GET /api/time 200
[2026-03-06 19:12:37] GET /random 404


---

## Technologies

- C
- POSIX sockets
- pthreads
- Linux networking

---

## Purpose

This project was created as a learning exercise to understand how real web servers work internally.

It explores:

- socket programming
- HTTP request parsing
- concurrency
- server architecture

---

## License

MIT License
