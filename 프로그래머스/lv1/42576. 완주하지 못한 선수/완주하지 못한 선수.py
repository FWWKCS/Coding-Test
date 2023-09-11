def solution(participant, completion):
    dict_participant = {
        # 선수 : 완주하지않은 인원
    }
    for p in participant :
        if p in dict_participant :
            dict_participant[p] += 1
        else :
            dict_participant[p] = 1

    for c in completion :
        dict_participant[c] -= 1

    for k in dict_participant.keys() :
        if dict_participant[k] == 1 :
            return k