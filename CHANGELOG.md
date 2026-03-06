## [0.1.0]

### Added
- Basic TCP socket server
- Server listens on port 8080
- Accepts incoming client connections

## [0.2.0]

### Added
- HTTP request reading from client socket
- Request buffer handling
- Debug printing of incoming HTTP requests

### Changed
- Updated server loop to process incoming data

## [0.3.0]

### Added
- HTTP request parser module
- HttpRequest structure
- Extraction of HTTP method, path, and version

### Changed
- Server now parses incoming HTTP requests instead of printing raw data
