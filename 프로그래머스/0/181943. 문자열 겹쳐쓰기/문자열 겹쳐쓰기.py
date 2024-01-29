def solution(my_string, overwrite_string, s):
    answer = ''
    
    m_s = list(my_string)
    for i in range(s, len(overwrite_string)+s):
        m_s[i] = overwrite_string[i-s]
    
    answer = ''.join(m_s)
    return answer