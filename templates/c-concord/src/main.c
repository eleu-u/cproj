#include <string.h>
#include "stdx/stringx.h"

#include <concord/discord.h>

#define BOT_TOKEN "TOKEN"

void on_ready(struct discord *client, const struct discord_ready *event) {
    printf("bot %s launched successfully\n", event->user->username);
}

void on_message(struct discord *client, const struct discord_message *event) {
    if (strcmpx(event->content, "ping")) {
        struct discord_create_message params = {.content = "pong"};
        discord_create_message(client, event->channel_id, &params, NULL);
    }
}

int main() {
    struct discord *client = discord_init(BOT_TOKEN);
    discord_add_intents(client, DISCORD_GATEWAY_MESSAGE_CONTENT);

    discord_set_on_ready(client, &on_ready);
    discord_set_on_message_create(client, &on_message);

    discord_run(client);
}