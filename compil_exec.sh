# Variables
PROJECT_NAME=CMakeSFMLProject

## Couleurs
rouge='\033[0;31m'
vert='\033[0;32m'
jaune='\033[1;33m'
reset='\033[0m'

afficher_aide()
{
	echo "Utilisation : $0 [options]"
	echo "Options:"
	echo " -c, --compile	Compiler le projet"
	echo " -r, --rm_build	Supprimer le dossier de build"
	echo " -h, --help	Afficher l'aide"
}

while [[ $# -gt 0 ]]; do
	case "$1" in
		-c|--compile)
			echo -e "${vert} Compilation du projet... ${reset}"
			cmake -S . -B build -DCMAKE_BUILD_TYPE=Realease &&
			cmake --build build --config Release &&
			echo -e "${vert} Compilation Terminée ${reset}"

			echo -e "${vert} Lancement de l'application ${reset}"
			./build/bin/${PROJECT_NAME}
			exit;;
		-r|--rm_build)
			echo -e "${vert} Nettoyage du dossier ./build... ${reset}"
			rm -rf ./build/bin/*
			echo -e "${vert} Nettoyage Terminée ${reset}"
			exit;;
		-h|--help)
			afficher_aide
			exit;;
		\?)
			echo -e "${rouge} Option Non Reconnue ${reset}"
			exit;;

	esac
	shift
done

## Execution
##./build/bin/${PROJECT_NAME}

