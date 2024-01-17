#ifdef LEADER_ENABLE

#    define LEADER_SEQ_(_1, _2, _3, _4, _5, NAME, ...) NAME
#    define LEADER_SEQ1(a) leader_sequence_one_key(a)
#    define LEADER_SEQ2(a, b) leader_sequence_two_keys(a, b)
#    define LEADER_SEQ3(a, b, c) leader_sequence_three_keys(a, b, c)
#    define LEADER_SEQ4(a, b, c, d) leader_sequence_four_keys(a, b, c, d)
#    define LEADER_SEQ5(a, b, c, d, e) leader_sequence_five_keys(a, b, c, d, e)

#    define LEADER_SEQ(...) LEADER_SEQ_(__VA_ARGS__, LEADER_SEQ5, LEADER_SEQ4, LEADER_SEQ3, LEADER_SEQ2, LEADER_SEQ1)(__VA_ARGS__)

#    define DEFINE_LEADERS(...) \
        do {                    \
            if (0) {            \
            }                   \
            __VA_ARGS__         \
        } while (0)

#    define LEADER(seq, body) \
        else if (seq) {       \
            body;             \
        }
#endif
