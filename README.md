# Cut tool

## Overview

This is a command-line utility written in C that reads a delimited text file (such as CSV or TSV) and prints specified fields to the console. It allows users to specify both the delimiter and the fields they want to extract.

## Features

- **Flexible Field Selection**: Users can specify multiple fields to print using the `-f` option.
- **Custom Delimiter**: Supports custom delimiters with the `-d` option, defaulting to a tab character if not specified.
- **Line Limiting**: Option to limit the number of lines processed from the file using a line count parameter.

## Requirements

- A C compiler (e.g., GCC)
- Standard C library

## Usage

```bash
./main -f<fields> -d<delimiter> <filename>
```
