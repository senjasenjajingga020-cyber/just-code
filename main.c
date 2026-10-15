#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_INPUT 256

static void to_lower(char *s) {
    for (; *s; ++s) *s = (char)tolower((unsigned char)*s);
}

static int contains(const char *haystack, const char *needle) {
    return strstr(haystack, needle) != NULL;
}

static void greet(void) {
    time_t t = time(NULL);
    struct tm *lt = localtime(&t);
    if (lt->tm_hour < 12)
        printf("Bot: Good morning! I'm ChatBot. How can I help you?\n");
    else if (lt->tm_hour < 18)
        printf("Bot: Good afternoon! I'm ChatBot. How can I help you?\n");
    else
        printf("Bot: Good evening! I'm ChatBot. How can I help you?\n");
}

static const char *reply(const char *input) {
    if (contains(input, "hello") || contains(input, "hi") || contains(input, "hey"))
        return "Hello there! What's on your mind?";
    if (contains(input, "how are you"))
        return "I'm just a program, but I'm running fine. Thanks for asking!";
    if (contains(input, "your name"))
        return "I'm ChatBot, a simple C program.";
    if (contains(input, "help"))
        return "I can chat about simple things. Try: hello, time, date, joke, bye.";
    if (contains(input, "time"))
        return "Sorry, my watch is broken. Check your system clock instead.";
    if (contains(input, "date"))
        return "I only know the date if you tell me. What day is it?";
    if (contains(input, "joke"))
        return "Why do programmers prefer dark mode? Because light attracts bugs.";
    if (contains(input, "weather"))
        return "I can't see outside, but I hope it's nice where you are.";
    if (contains(input, "bye") || contains(input, "goodbye"))
        return "Goodbye! Have a great day.";
    if (contains(input, "thank"))
        return "You're welcome!";
    return "I don't understand that yet. Try typing 'help'.";
}

int main(void) {
    char input[MAX_INPUT];

    greet();
    printf("Bot: Type 'bye' to exit.\n\n");

    while (1) {
        printf("You: ");
        if (!fgets(input, sizeof(input), stdin)) break;

        input[strcspn(input, "\r\n")] = '\0';
        if (input[0] == '\0') continue;

        char lower[MAX_INPUT];
        strncpy(lower, input, MAX_INPUT - 1);
        lower[MAX_INPUT - 1] = '\0';
        to_lower(lower);

        printf("Bot: %s\n\n", reply(lower));

        if (contains(lower, "bye") || contains(lower, "goodbye")) break;
    }

    return 0;
}
