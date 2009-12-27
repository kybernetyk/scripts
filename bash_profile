

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

##
# Your previous /Users/jrk/.bash_profile file was backed up as /Users/jrk/.bash_profile.macports-saved_2009-12-27_at_04:38:44
##

# MacPorts Installer addition on 2009-12-27_at_04:38:44: adding an appropriate PATH variable for use with MacPorts.
export PATH=/opt/local/bin:/opt/local/sbin:$PATH
# Finished adapting your PATH environment variable for use with MacPorts.

