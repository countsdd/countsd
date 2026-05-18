import os

def is_float(value):
        try:
            float(value)
            return True
        except ValueError:
            return False

def values(data):
        data = data.strip()
        if data == '':
            return '', 'str'
        elif data.isdigit() or (data[0] == '-' and data[1:].isdigit()):
            return int(data), 'int'
        elif is_float(data):
            return float(data), 'float'
        else:
            return data, 'str'

def delimiter(line):
    delimiters = [',', '\t', '|', ';']
    for delim in delimiters:
        if delim in line:
            return delim
    return ','


def has_header(data):
    first = data[0].split(delimiter(data[0]))
    for elem in first:
        val, typ = values(elem)
        if typ == 'str':
            return True
    return False

Dir = 'data1'
frames = []

for file in os.listdir(Dir):
    frames.append(Dir + '/' + file)

with open("frames_out", "w") as file_out:
    for i in range(len(frames)):
            
        with open(frames[i], "r", encoding='utf-8') as f:
            data = f.readlines()
            first_st = has_header(data)
        dell = delimiter(data[0])
        header = []
        start = 0
            
        if first_st:
            header = data[0].strip().split(dell)
            start = 1
        types_list = []
        data_list = []

        if start < len(data):
            first_line = data[start].split(dell)
            for part in first_line:
                val, typ = values(part)
                types_list.append(typ)

        for line in data[start:]:
            parts = line.strip().split(dell)
            values_list = []

            for part in parts:
                val, typ = values(part)
                values_list.append(val)

            data_list.append(values_list)

        print({
            'header': header,
            'data': data_list,
            'types': types_list
        })

        print()
