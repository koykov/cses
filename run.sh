#!/usr/bin/env bash

# Init variables.
BUILD=0
TARGET=""

# Parse cli options.
while [[ "$#" -gt 0 ]]; do
    case $1 in
        -t|--target) TARGET="$2"; shift;;
        -b|--build) BUILD=1;;
        *) arg="$1"; shift;;
    esac;
    shift;
done

# Prepare environment.
if [[ "$BUILD" == "1" ]]
then
    ./build.sh
fi

if [[ "$TARGET" ]]
then
    # Single target passed.
    echo "Testing target $TARGET"

    # Check binary exists.
    BIN="bin/$TARGET"

    if [[ ! -f "$BIN" ]]
    then
        echo "Target binary doesn't exists: $BIN"
        echo "Execute 'build.sh' first or use options --build"
        exit 1
    fi

    # Check mocks dir exists.
    MOCKS="mocks/$TARGET"

    if [[ ! -d "$MOCKS" ]]
    then
        echo "Mocks dir doesn't exists: $MOCKS"
        exit 1
    fi

    for f in "$MOCKS"/*; do
        if [[ "$f" == *-in.txt ]]
        then
            idx=${f%-in.txt}
            ef="$idx-out.txt"

            echo -e " * testing input data $f ... \c"
            ns_s=`date +%s%N`
            r=`cat "$f" | "$BIN"`
            ns_e=`date +%s%N`

            e=`cat "$ef"`

            if [[ "$r" == "$e" ]]
            then
                echo "passed in $((${ns_e}-${ns_s})) ns"
            else
                echo -e "failed\nexpected:\n$e\ngot:\n$r"
            fi

        fi
    done
else
    # All targets selected.
    echo "TODO all targets"
fi
