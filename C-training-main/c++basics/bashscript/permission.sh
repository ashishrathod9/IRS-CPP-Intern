#!/bin/bash

for file in *.sh
do
    if [ ! -x "$file" ]
    then
        echo "File '$file' is not executable."
        read -p "Do you want to add execute permission? (y/n): " choice

        if [[ "$choice" == "y" || "$choice" == "Y" ]]
        then
            chmod +x "$file"
            echo "✅ Permission added to $file"
        else
            echo "⏩ Skipped $file"
        fi

    else
        echo "✔ $file already executable"
    fi
done

echo "Permission check complete ✅"

