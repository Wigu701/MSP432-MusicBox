#include <outputs/include/music_player.h>


QueueHandle_t Queue_MusicPlayer_Driver;


void Task_musicPlayer(void *pvParameters) {
    MESSAGE_t command;
    int curSong = 0;
    int stopCommand = -1;
    titleString = songs[curSong].title;
    authorString = songs[curSong].author;

    while (1) {
        xQueueReceive(Queue_MusicPlayer_Driver, &command, portMAX_DELAY);

        // Based on command type
        if (command.action == FLICK) {
            switch (command.direction) {
                case UP:
                    curSong = (curSong + 2) % TOTAL_SONGS;
                    break;
                case RIGHT:
                    curSong = (curSong + 1) % TOTAL_SONGS;
                    break;
                case DOWN:
                    curSong = (curSong -= 2) < 0 ? TOTAL_SONGS - 1 : curSong;
                    break;
                case LEFT:
                    curSong = (--curSong) < 0 ? TOTAL_SONGS - 1 : curSong;
                default:
                    break;
            }
            titleString = songs[curSong].title;
            authorString = songs[curSong].author;
        } else {
            if (command.direction == UP) {
                xQueueSendToBack(Queue_Sound, &curSong, portMAX_DELAY);
            } else {
                xQueueSendToBack(Queue_Sound, &stopCommand, portMAX_DELAY);
            }
        }
    }
}
