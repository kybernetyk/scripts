

function wman() 
{
   url="man -w ${1} | sed 's#.*\(${1}.\)\([[:digit:]]\).*\$#http://developer.apple.com/documentation/Darwin/Reference/ManPages/man\2/\1\2.html#'"
   open `eval $url`
}

function pman()
{
man -t ${1} | open -f -a /Applications/Preview.app

}

export CLICOLOR="true"
export LSCOLORS="exfxcxdxbxegedabagacad"

test -r /sw/bin/init.sh && . /sw/bin/init.sh
