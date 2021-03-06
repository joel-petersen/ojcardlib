/* OneJoker card library <http://lcrocker.github.io/onejoker/cardlib>
 *
 * To the extent possibile under law, Lee Daniel Crocker has waived all
 * copyright and related or neighboring rights to this work.
 * <http://creativecommons.org/publicdomain/zero/1.0/>
 *
 * "Hello World" example.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ojcardlib.h"

int main(int argc, char *argv[]) {
    oj_card db[52], hb[5];
    char text[20];
    oj_cardlist deck, hand;

    ojl_new(&deck, db, 52);
    ojl_fill(&deck, 52, OJD_STANDARD);
    ojl_shuffle(&deck);

    ojl_new(&hand, hb, 5);
    for (int i = 0; i < 5; ++i) ojl_append(&hand, ojl_pop(&deck));

    ojl_text(&hand, text, sizeof(text));
    printf("%s\n", text);

    (void)(argc);
    (void)(argv); // keep -Wextra happy
    return 0;
}
