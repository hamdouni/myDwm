#!/bin/bash

# Works with a semver file VERSION in current directory,

# Display current version, automatically suggest a "patch" 
# version update, and ask for input to use suggestion, 
# or a newly entered value.

# Then the script will pull list of changes from git log, 
# prepend this to CHANGES file (under the title of the new version
# number) and create a GIT tag.

# Then it will copy the VERSION file to src/version so it is
# displayed on the web app.

if [ ! -f VERSION ]; then
    echo "Could not find a VERSION file"
    exit -1
fi

BASE_STRING=`cat VERSION`
BASE_LIST=(`echo $BASE_STRING | tr '.' ' '`)
V_MAJOR=${BASE_LIST[0]}
V_MINOR=${BASE_LIST[1]}
V_PATCH=${BASE_LIST[2]}
echo "Current version : $BASE_STRING"
V_PATCH=$((V_PATCH + 1))
SUGGESTED_VERSION="$V_MAJOR.$V_MINOR.$V_PATCH"
read -p "Enter a version number [$SUGGESTED_VERSION]: " INPUT_STRING
if [ "$INPUT_STRING" = "" ]; then
    INPUT_STRING=$SUGGESTED_VERSION
fi
echo "Will set new version to be $INPUT_STRING"
echo $INPUT_STRING > VERSION
echo "Version $INPUT_STRING:" > tmpfile
git log --pretty=format:" - %s" "v$BASE_STRING"...HEAD >> tmpfile
echo "" >> tmpfile
echo "" >> tmpfile
cat CHANGES >> tmpfile
mv tmpfile CHANGES
echo '#define VERSION "'$INPUT_STRING'"' > ./programs/slstatus/version.h
git add CHANGES VERSION ./programs/slstatus/version.h

git commit -m "$INPUT_STRING"
git tag -a -m "Tagging version $INPUT_STRING" "v$INPUT_STRING"
