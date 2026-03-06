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

## [0.4.0]

### Added
- Static file serving from public directory
- HTTP response generation
- Basic Content-Type header
- 404 Not Found response

### Changed
- Server now responds with HTML content instead of only printing requests

## [0.5.0]

### Added
- Multithreaded request handling using pthread
- Thread-per-connection architecture
- Dedicated client handler function

### Changed
- Server now processes requests concurrently

## [0.6.0]

### Added
- Request logging system
- Content-Type detection for common file types
- Automatic routing of "/" to index.html

### Changed
- HTTP responses now include correct Content-Type headers

### Logging
Requests are now recorded in logs/server.log.

## [0.7.0]

### Fixed
- Fixed incorrect HTTP response format where headers appeared after body
- Removed duplicate HTML output
- Ensured correct HTTP header ordering

### Improved
- Cleaned server response handling
- Verified correct output using curl

## v1.0.0 

### Added
- Multi-threaded HTTP server
- Static file serving
- Basic API routing system
- Logging system
- Content-Type detection
- Automatic `/` → `index.html`
- 404 error handling

### Improved
- Logging timestamp format using ISO-style time
- Cleaner routing architecture

### Fixed
- Duplicate response issues
