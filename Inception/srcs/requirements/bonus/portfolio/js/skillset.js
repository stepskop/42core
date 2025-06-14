const primarySkillsetGrid = document.getElementById("primary-skillset");
//const primaryTechnologies = ["nestjs", "mongo", "express", "prisma", "socketio", "nodejs", "linux", "typescript", "clang", "sveltekit", "capacitor", "playwright", "docker", "gitlab"]
const primaryTechnologies = [
	{ name: "nestjs", link: "https://nestjs.com" },
	{ name: "mongo", link: "https://mongodb.com" },
	{ name: "expressjs", link: "https://expressjs.com" },
	{ name: "prisma", link: "https://prisma.io" },
	{ name: "socketio", link: "https://socket.io" },
	{ name: "nodejs", link: "https://nodejs.org" },
	{ name: "linux", link: "https://gnu.org" },
	{ name: "typescript", link: "https://typescriptlang.org" },
	{ name: "c", link: "https://gnu.org/software/gnu-c-manual/gnu-c-manual" },
	{ name: "sveltekit", link: "https://kit.svelte.dev" },
	{ name: "capacitor", link: "https://capacitorjs.com" },
	{ name: "playwright", link: "https://playwright.dev" },
	{ name: "docker", link: "https://docker.com" },
	{ name: "gitlab", link: "https://gitlab.com" }
  ];

const primaryClasslist = "xl:row-start-5 xl:row-end-8 border-highlight w-full aspect-square"
renderSkillset(primarySkillsetGrid, primaryTechnologies, primaryClasslist);

const secondarySkillsetGrid = document.getElementById("secondary-skillset");
const secondaryTechnologies = [
	{ name: "vue", link: "https://vuejs.org" },
	{ name: "react", link: "https://reactjs.org" },
	{ name: "kubernetes", link: "https://kubernetes.io" },
	{ name: "ansible", link: "https://ansible.com" },
	{ name: "postgres", link: "https://postgresql.org" },
	{ name: "figma", link: "https://figma.com" },
	{ name: "tailwind", link: "https://tailwindcss.com" },
	{ name: "golang", link: "https://go.dev" }
  ]
const secondaryClasslist = "xl:row-start-4 xl:row-end-7 border-highlight w-full aspect-square"
renderSkillset(secondarySkillsetGrid, secondaryTechnologies, secondaryClasslist);

function renderSkillset(gridElement, technologies, defaultClass) {
	for (let i = 0; i < technologies.length; i++)
	{
		const skillLink = document.createElement("a")
		skillLink.classList.value = defaultClass
		skillLink.href = technologies[i].link
		skillLink.target = "blank_"
		skillLink.classList.add("relative", "group")
		const tooltip = document.createElement("span")
		tooltip.classList.value = "bottom-2 absolute hidden group-hover:flex text-xs w-full justify-center items center"
		tooltip.innerHTML = technologies[i].name.charAt(0).toUpperCase() + String(technologies[i].name).slice(1)
		const newImg = document.createElement("img")
		if (technologies[i].name === "golang")
		{
			const learningText = document.createElement("span")
			learningText.innerHTML = "Learning"
			learningText.classList.value = "-bottom-6 absolute flex text-xxs text-lightText w-full justify-center"
			skillLink.append(newImg, tooltip, learningText)

		} else
			skillLink.append(newImg, tooltip)
		newImg.src = `./assets/images/tech/${technologies[i].name}.svg`
		newImg.classList.value = "w-full flex group-hover:-translate-y-3 ease-in-out duration-300"
		if (i < technologies.length - 1)
			skillLink.classList.add("xl:border-r")
		gridElement.appendChild(skillLink)
	}
}