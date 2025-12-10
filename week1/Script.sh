
while true; do
    clear
    echo "==========================="
    echo "   System Management Menu"
    echo "==========================="
    echo "1. Show Disk Usage"
    echo "2. Show Memory Usage"
    echo "3. Show Running Processes"
    echo "4. Show Network Connections"
    echo "5. Update System"
    echo "6. Exit"
    echo "==========================="
    read -p "Enter your choice [1-6]: " CHOICE

    case $CHOICE in
        1)
            echo
            df -h
            ;;
        2)
            echo
            free -h
            ;;
        3)
            echo
            ps aux | head -20
            ;;
        4)
            echo
            ss -tuln
            ;;
        5)
            echo
            sudo apt update && sudo apt upgrade -y
            ;;
        6)
            echo "Exiting..."
            exit 0
            ;;
        *)
            echo "Invalid choice. Please try again."
            ;;
    esac

    echo
    read -p "Press Enter to continue..."
done
