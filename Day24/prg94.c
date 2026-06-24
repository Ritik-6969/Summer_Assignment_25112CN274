#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void compress_string(const char *input, char *output, size_t max_len) {
    size_t in_len = strlen(input);
    size_t out_pos = 0;

    for (size_t i = 0; i < in_len; ) {
        char current = input[i];
        size_t count = 0;

        while (i < in_len && input[i] == current) {
            count++;
            i++;
        }

        int written = snprintf(output + out_pos, max_len - out_pos, "%c%zu", current, count);
        if (written < 0 || (size_t)written >= max_len - out_pos) {
            break;
        }
        out_pos += (size_t)written;
    }

    if (out_pos >= max_len) {
        output[max_len - 1] = '\0';
    } else {
        output[out_pos] = '\0';
    }
}

int main(void) {
    char input[1024];
    char output[2048];

    printf("Enter a string to compress: ");
    if (!fgets(input, sizeof(input), stdin)) {
        return 0;
    }

    input[strcspn(input, "\n")] = '\0';

    compress_string(input, output, sizeof(output));

    printf("Compressed string: %s\n", output);
    return 0;
}
