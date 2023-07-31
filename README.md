# WinWidgets Core

This is the Core library for WinWidgets. It contains low-level functions that are exported to use in the main [WinWidgets project](https://www.github.com/beyluta/WinWidgets).

## Development

This project was compiled with `g++ 10.3.0`.

Open the CMD or PowerShell in the root of the project and run the command the following command to compile the project into an `.exe` for testing.

```
make
```

Run this command to execute the program and test it.

```
make run
```

When you are done, run this command to compile the project into a `.dll` for use in the main project.

```
make dll
```

## Contributing

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Add yourself to the CONTRIBUTORS.txt file
6. Open a Pull Request

## Conventions

- Use `camelCase` for variables and functions
- Use only `C` syntax for exportable functions
- Write at least one test for each function

<i>For writing tests, `C++` syntax may be used.</i>
