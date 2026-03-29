Decoy File Trap System

## Overview
The Decoy File Trap System is a lightweight security project developed using C and Linux system programming. It monitors access to predefined decoy files
and logs any suspicious activity in real time. The goal is to detect unauthorized or unexpected file access using a simple and efficient approach.

## Objective
To identify and record access attempts to sensitive-looking files by monitoring a directory and comparing accessed files against a predefined list of decoy files.

## How It Works

1. The program reads a configuration file containing the list of decoy files.
2. It initializes a monitoring mechanism for a specific directory using Linux inotify.
3. The system waits for file access events.
4. When a file is accessed, the program checks whether it is listed as a decoy file.
5. If a match is found, the access counter is incremented.
6. Once the threshold is reached, the event is logged with a timestamp.

## Project Structure

```
decoy_project/
│
├── src/
│   ├── main.c
│   ├── monitor.c
│   ├── logic.c
│   └── logic.h
│
├── config/
│   └── config.txt
│
├── decoy_files/
│   ├── passwords.txt
│   ├── salary.txt
│   └── secret.doc
│
├── logs/
│   └── log.txt
│
├── build/
│   └── app
```

## Configuration
The file `config/config.txt` contains the list of files to be monitored:

```
decoy_files/passwords.txt
decoy_files/salary.txt
decoy_files/secret.doc
```

This allows modification of monitored files without changing the source code.

## Build and Execution
Compile the program:

```
gcc src/main.c src/logic.c src/monitor.c -o build/app
```
Run the executable:
```
./build/app
```

## Testing
Access any decoy file using a command such as:

```
cat decoy_files/passwords.txt
```

After multiple accesses, the system records the activity in:

```
logs/log.txt
```
## Features
* Real-time file access monitoring
* Configurable list of decoy files
* Simple and efficient implementation in C
* Log generation with timestamps

## Limitations
* Supported only on Linux systems (uses inotify)
* Detects file access events only
* Does not prevent access or notify externally

## Future Enhancements
* Real-time alert mechanisms (email or notifications)
* Graphical interface for monitoring
* Support for additional operating systems
* Advanced behavior analysis

## Author
Jeeno SK





