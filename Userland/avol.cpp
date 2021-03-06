#include <LibAudio/ABuffer.h>
#include <LibAudio/AClientConnection.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    CEventLoop loop;
    auto audio_client = AClientConnection::construct();
    audio_client->handshake();

    if (argc > 1) {
        int new_volume = atoi(argv[1]);
        audio_client->set_main_mix_volume(new_volume);
    }

    int volume = audio_client->get_main_mix_volume();
    printf("Volume: %d\n", volume);
    return 0;
}
