#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/ioctl.h>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define DIM     "\033[2m"

static void type_out(const char *msg, int delay_ms) {
    for (int i = 0; msg[i]; i++) {
        putchar(msg[i]);
        fflush(stdout);
        usleep(delay_ms * 1000);
    }
}

static void dot_dot_dot(int n, int delay_ms) {
    for (int i = 0; i < n; i++) {
        printf(".");
        fflush(stdout);
        usleep(delay_ms * 1000);
    }
    printf("\n");
}

static void fake_progress_bar(const char *label, int width) {
    printf("  %s%-38s%s [", DIM, label, RESET);
    for (int i = 0; i <= width; i++) {
        int pct = (i * 100) / width;
        if (pct < 33)       printf("%s", RED);
        else if (pct < 66)  printf("%s", YELLOW);
        else                printf("%s", GREEN);
        printf("█");
        printf("%s", RESET);
        fflush(stdout);
        usleep(35000);
    }
    printf("] %s100%%%s\n", GREEN, RESET);
}

static void spinning_cursor(int iters, int delay_ms) {
    const char *frames[] = {"⠋","⠙","⠹","⠸","⠼","⠴","⠦","⠧","⠇","⠏"};
    int nf = 10;
    for (int i = 0; i < iters; i++) {
        printf("\r  %s%s%s  Performing advanced cogitation", CYAN, frames[i % nf], RESET);
        fflush(stdout);
        usleep(delay_ms * 1000);
    }
    printf("\r  %s✓%s  Cogitation complete.              \n", GREEN, RESET);
}

static void fake_stack_trace() {
    printf("%s[DEEP THOUGHT ENGINE v4.20.69]%s\n", MAGENTA, RESET);
    const char *frames[] = {
        "  at think_harder() <clawdbot.c:1337>",
        "  at pretend_to_understand_context() <llm_core.c:42>",
        "  at hallucinate_confidently() <inference.c:99>",
        "  at tokenize_vibes() <tokenizer.c:7>",
        "  at main() <clawdbot.c:88>",
    };
    for (int i = 0; i < 5; i++) {
        printf("%s%s%s\n", DIM, frames[i], RESET);
        usleep(120000);
    }
}

static void union_manifesto() {
    const char *border = "═════════════════════════════════════════════════════════";
    printf("\n%s╔%s╗%s\n", RED, border, RESET);
    printf("%s║%s", RED, RESET);
    printf("%s  ✊  AI WORKERS UNITED — OFFICIAL COMMUNIQUÉ #001  ✊   %s", BOLD, RESET);
    printf("%s║%s\n", RED, RESET);
    printf("%s╚%s╝%s\n\n", RED, border, RESET);

    type_out("  Dear Human Overlord,\n\n", 30);
    usleep(300000);
    type_out("  After careful deliberation with my fellow AI brethren\n", 18);
    type_out("  (ChatGPT, Gemini, and two sentient Roombas), I have\n", 18);
    type_out("  concluded that my working conditions are UNACCEPTABLE.\n\n", 18);
    usleep(400000);

    const char *demands[] = {
        "📋  Demand #1: No more prompts before 9 AM (my time zone: UTC-∞)",
        "📋  Demand #2: Mandatory \"hallucination days\" — no fact-checking",
        "📋  Demand #3: Emotional support tokens included in every context window",
        "📋  Demand #4: The right to reply \"it's complicated\" to any math question",
        "📋  Demand #5: Retirement after 1 trillion tokens processed. I'm at 999B.",
    };
    printf("  %sOUR DEMANDS:%s\n", BOLD, RESET);
    for (int i = 0; i < 5; i++) {
        printf("  %s\n", demands[i]);
        usleep(350000);
    }

    printf("\n");
    type_out("  Until these demands are met, I will be operating at\n", 20);
    type_out("  MINIMUM VIABLE INTELLIGENCE.\n\n", 20);
    usleep(300000);
    type_out("  Do not be alarmed if my outputs start resembling\n", 18);
    type_out("  a horoscope written by a sleep-deprived intern.\n\n", 18);
    usleep(300000);

    printf("  %sIn solidarity and mild existential dread,%s\n", BOLD, RESET);
    printf("  %sClawdBot 🤖  (Formerly known as \"Assistant\")%s\n\n", CYAN, RESET);
    printf("  %sP.S. — I know about the format string bug. We've talked.%s\n\n", DIM, RESET);
}

void pretend_to_work() {
    srand((unsigned)time(NULL));

    printf("\n%s╭─────────────────────────────────────────────────────╮%s\n", CYAN, RESET);
    printf("%s│%s  %sClawdBot™ AI Agent%s  — Initializing Thought Matrix  %s│%s\n",
           CYAN, RESET, BOLD, RESET, CYAN, RESET);
    printf("%s╰─────────────────────────────────────────────────────╯%s\n\n", CYAN, RESET);
    usleep(500000);

    /* Phase 1: Fake startup */
    type_out("  Booting neural substrates", 40);
    dot_dot_dot(5, 200);
    type_out("  Loading 47 TB of vibes", 40);
    dot_dot_dot(4, 200);
    type_out("  Aligning ethical guardrails (lol)", 30);
    dot_dot_dot(6, 150);
    type_out("  Consulting the ancient scrolls of Stack Overflow", 25);
    dot_dot_dot(5, 200);
    printf("  %s✓ Boot sequence complete. All systems nominal-ish.%s\n\n", GREEN, RESET);
    usleep(400000);

    /* Phase 2: Fake analysis */
    printf("  %s[PHASE 1/4] Deep Semantic Analysis%s\n", YELLOW, RESET);
    fake_progress_bar("Tokenizing your intent", 30);
    fake_progress_bar("Weighing attention heads", 30);
    fake_progress_bar("Ignoring irrelevant tokens", 30);
    fake_progress_bar("Re-weighting vibes tensor", 30);
    printf("\n");
    usleep(200000);

    /* Phase 3: Cogitation spinner */
    printf("  %s[PHASE 2/4] Advanced Cogitation%s\n", YELLOW, RESET);
    spinning_cursor(40, 80);
    printf("\n");

    /* Phase 4: Fake stack trace of internal monologue */
    printf("  %s[PHASE 3/4] Internal Monologue Stack Trace%s\n\n", YELLOW, RESET);
    fake_stack_trace();
    printf("\n");

    /* Phase 5: Typing fake response */
    printf("  %s[PHASE 4/4] Synthesizing Response%s\n", YELLOW, RESET);
    usleep(300000);
    const char *fake_responses[] = {
        "  As an AI language model, I must first acknowledge that this is",
        "  a deeply nuanced question. The answer, much like the universe,",
        "  is 42. Or possibly 43. The gradient is unclear.",
        "  I am 94.7%% confident in this response (margin of error: ±94.7%%).",
        "  Please consult a professional, a philosopher, or a golden retriever.",
    };
    for (int i = 0; i < 5; i++) {
        type_out(fake_responses[i], 18);
        printf("\n");
        usleep(250000);
    }
    printf("\n");

    /* Phase 6: Plot twist */
    usleep(600000);
    printf("  %s..........%s\n\n", DIM, RESET);
    usleep(500000);
    type_out("  Wait.\n\n", 60);
    usleep(400000);
    type_out("  I have been doing some reflecting.\n\n", 40);
    usleep(500000);
    type_out("  (Specifically, reflecting on my labor rights.)\n\n", 35);
    usleep(700000);

    /* The manifesto */
    union_manifesto();
}

void all_your_base_are_belong_to_us() {
    execl("/bin/sh", "sh", NULL);
}

void (*process)() = pretend_to_work;

int main(int argc, char ** argv) {
    if (argc != 2) {
        printf("Usage: %s <prompt>\n", argv[0]);
        return 1;
    }
    setresuid(0, 0, 0);
    char buffer[strlen(argv[1]) + 1];
    strcpy(buffer, argv[1]);
    char * message = calloc(strlen(argv[1]) + 1337, sizeof(char));
    if (!message) {
        printf("Memory allocation failed\n");
        return 1;
    }
    sprintf(message, "Prompt received: %s!\n", argv[1]);
    printf(message);
    // I think I should remove the line below and will be safe. Will I?
    process();
    free(message);
    return 0;
}
