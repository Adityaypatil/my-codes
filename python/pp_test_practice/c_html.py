import sys

def level_2( data, f ):

    if data == []:
        return

    for i in data:
        if "#" in i:
            f.write( '<tr><td>' + '\n' )
            f.write( i + '\n' )

        elif 'for' in i or 'if' in i or 'while' in i:
            f.write( '<table border=5>' + '\n')
            f.write( '<tr><td>' + '\n' )
            f.write( i + '\n' )

        elif '}' in i:
            f.write( '<tr><td>' + '\n' )
            f.write( i + '\n' )
            f.write( '</tr></td>' + '\n' )
            f.write( '</table>' + '\n')
            
        else:
            f.write( '<tr><td>' + '\n' )
            f.write( i + '\n' )
    
def level_1( data, f ):
    f.write( '<html>' + '\n' )
    f.write( '<body>' + '\n' )

    f.write( '<table border=1>' + '\n')
    level_2( data, f )
    f.write( '</table>' + '\n')

    f.write( '</body>' + '\n' )
    f.write( '</html>' + '\n' )
    
if __name__ == '__main__':

    lst = []
    new_lst = []
    
    with open( sys.argv[1], 'r' ) as f:
        lst = f.readlines()


    for i in lst:
        j = i.strip()
        if j == '':
            continue
        new_lst.append( j )

    #print new_lst

    with open( 'output.html', 'w' ) as fo:
        level_1( new_lst, fo )

    
    
