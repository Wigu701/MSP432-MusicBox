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
        xQueueReset(Queue_MusicPlayer_Driver);
        xQueueReceive(Queue_MusicPlayer_Driver, &command, portMAX_DELAY);

        // Based on command type
        if (command.action == FLICK) {
            switch (command.direction) {
                case DOWN:
                    trackNum = (++trackNum > songs[curSong].tracks) ? 0 : trackNum;
                    break;
                case RIGHT:
                    curSong = (curSong + 1) % TOTAL_SONGS;
                    trackNum = 1;
                    break;
                case UP:
                    trackNum = (--trackNum) < 0 ? songs[curSong].tracks : trackNum;
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
            if (masterPlayer && command.action == DUET) continue;
            if (command.direction == UP) {
                int playCommand = curSong | (trackNum << TRACK_OFFSET);
                if (command.action == CLICK) masterPlayer = true;
                xQueueSendToBack(Queue_Sound, &playCommand, portMAX_DELAY);
            } else {
                xQueueSendToBack(Queue_Sound, &stopCommand, portMAX_DELAY);
            }
        }
    }
}
