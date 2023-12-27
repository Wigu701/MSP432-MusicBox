#include <outputs/include/music_player.h>


QueueHandle_t Queue_MusicPlayer_Driver;


void Task_musicPlayer(void *pvParameters) {
    MESSAGE_t command;
    int curSong = 0;
    int stopCommand = -1;
    titleString = songs[curSong].title;
    authorString = songs[curSong].author;
    trackNum = 1;

    while (1) {
        xQueueReceive(Queue_MusicPlayer_Driver, &command, portMAX_DELAY);

        // Based on command type
        if (command.action == FLICK) {
            switch (command.direction) {
                case UP:
                    trackNum = (++trackNum > songs[curSong].tracks + 1) ? 1 : trackNum;
                    break;
                case RIGHT:
                    curSong = (curSong + 1) % TOTAL_SONGS;
                    trackNum = 1;
                    break;
                case DOWN:
                    trackNum = (--trackNum) < 1 ? songs[curSong].tracks + 1 : trackNum;
                    break;
                case LEFT:
                    curSong = (--curSong) < 0 ? TOTAL_SONGS - 1 : curSong;
                    trackNum = 1;
                default:
                    break;
            }
            titleString = songs[curSong].title;
            authorString = songs[curSong].author;
        } else {
            if (command.direction == UP) {
                int playCommand = curSong | (trackNum << TRACK_OFFSET);
                xQueueSendToBack(Queue_Sound, &playCommand, portMAX_DELAY);
            } else {
                xQueueSendToBack(Queue_Sound, &stopCommand, portMAX_DELAY);
            }
        }
    }
}
