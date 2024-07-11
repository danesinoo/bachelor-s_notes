import re

# Define the new grammar rules as functions
def parse_line(s):
    target = get_target(s)
    full_tree = parse_full_tree(s)
    return f'{target} |BT| {full_tree}|ET|'

def get_target(s):
    match = re.match(r'\((\d) (.*)\)', s)
    if match:
        sentiment = match.group(1)
        return sentiment
    else:
        raise ValueError("Invalid input format")

def parse_full_tree(s):
    s = s.strip()
    return s.replace(') (', ')(')
    
file = open('dev.txt', 'r')
result = list(map(lambda x: parse_line(x), file.readlines()))
file.close()

file = open('dev.svmlight.txt', 'w')
file.write('\n'.join(result))
file.close()
