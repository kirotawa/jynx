#! /bin/bash


# Get log
if [ $1 = '-l' ]
then
    REPO=$2
    PATH_FILE=$3
    cd $REPO && git log $PATH_FILE | grep commit
# Or get patch given a SHA commit
elif [ $1 = '-p' ]
then
    REPO=$2
    SHA=$3
    BASENAME=`basename $REPO`
    COMPLETE_PATH="/tmp/$BASENAME"
    # If we have temp directory to REPO basename 
    if [ -d $COMPLETE_PATH ]
    then
        if [ -f $COMPLETE_PATH/$SHA.patch ]
        then
            exit 0
        else
            cd $REPO && git format-patch -1 $SHA --stdout > $COMPLETE_PATH/$SHA.patch
        fi
    # Else we create one and create the patch file to be pulled by QT
    else
        mkdir $COMPLETE_PATH
        cd $REPO && git format-patch -1 $SHA --stdout > $COMPLETE_PATH/$SHA.patch
    fi
fi
