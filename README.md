# Simple Chat Bot

A simple rule-based chat bot written in C. No dependencies, just the C standard library.

## Features

- Keyword-based replies (hello, help, joke, weather, bye, ...)
- Time-based greeting (morning / afternoon / evening)
- Case-insensitive input

## Build

gcc main.c -o chatbot -Wall -Wextra

## Run

./chatbot

Or on Windows:

gcc main.c -o chatbot.exe -Wall -Wextra
.\chatbot.exe

## Example

Bot: Good evening! I'm ChatBot. How can I help you?
Bot: Type 'bye' to exit.

You: hello
Bot: Hello there! What's on your mind?

You: tell me a joke
Bot: Why do programmers prefer dark mode? Because light attracts bugs.

You: bye
Bot: Goodbye! Have a great day.

## Adding Replies

Open `main.c` and add a new rule inside the `reply()` function:

    if (contains(input, "coffee"))
        return "Coffee keeps me compiling!";

## License

MIT
