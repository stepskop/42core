const experiencesData = [	
	{
		name: "Backend engineer",
		company: {
			name: "Apify",
			link: "https://apify.com"
		},
		duration: {
			from: "March 2025",
			to: "Present"
		},
		image: "apify.svg",
		details: {
			office: "Hybrid",
			type: "Part-time",
			location: "Prague"
		},
		color: "#98D800",
		description: "Maintaining API, backend services and infra, of the big scale and highly available systems. Deploying custom made web scrapers and automation tools."
	},
	{
		name: "Infra / DevOps",
		company: {
			name: "HAXAGON",
			link: "https://haxagon.cz"
		},
		duration: {
			from: "May 2024",
			to: "Present"
		},
		image: "haxagon.svg",
		details: {
			office: "Remote",
			type: "Part-time",
			location: "Prague"
		},
		color: "#9562FE",
		description: "Creating and maintaining Ansible roles, Building new deployment images for AWS, extending monitoring using linux system level monitoring for Docker containers."
	},
	{
		name: "Backend developer",
		company: {
			name: "HAXAGON",
			link: "https://haxagon.cz"
		},
		duration: {
			from: "Apr 2024",
			to: "Present"
		},
		image: "haxagon.svg",
		details: {
			office: "Remote",
			type: "Part-time",
			location: "Prague"
		},
		color: "#9562FE",
		description: "Backend logic and features including API controllers and DB management including permissions and overall Access Control List."
	},
	{
		name: "Fullstack developer",
		company: {
			name: "Pokhec",
			link: undefined
		},
		duration: {
			from: "Sep 2024",
			to: "1 month"
		},
		image: "pokhec.svg",
		details: {
			office: "Remote",
			type: "Contract",
			location: "Prague"
		},
		color: "#6565B2",
		description: "Creation and management of website in Sveltekit about mentoring programs including CMS built on top of firestore."
	},
	{
		name: "CyberSec CTF creator",
		company: {
			name: "HAXAGON",
			link: "https://haxagon.cz"
		},
		duration: {
			from: "Sep 2023",
			to: "5 months"
		},
		image: "haxagon.svg",
		details: {
			office: "Remote",
			type: "Part-time",
			location: "Prague"
		},
		color: "#9562FE",
		description: "Idea making and building cybersecurity scenarios for our CTF platform. Providing challenge Docker images with e-shop scale apps."
	},
	{
		name: "Testing engineer",
		company: {
			name: "HAXAGON",
			link: "https://haxagon.cz"
		},
		duration: {
			from: "Apr 2023",
			to: "2 years"
		},
		image: "haxagon.svg",
		details: {
			office: "Remote",
			type: "Part-time",
			location: "Prague"
		},
		color: "#9562FE",
		description: "Creation of custom framework for E2E testing built on top of Playwright. Managing CI/CD pipelines. Developing E2E and ACL testing."
	},
	{
		name: "Coding tutor",
		company: {
			name: "Logiscool",
			link: "https://logiscool.com/cz/"
		},
		duration: {
			from: "Jan 2022",
			to: "1 year"
		},
		image: "logiscool.svg",
		details: {
			office: "On-site",
			type: "Part-time",
			location: "Prague"
		},
		color: "#BC1142",
		description: "Coding tutor, teaching basics of programming and computer science."
	}
]

const experiencesElement = document.getElementById("experiences")

for (let i = 0; i < experiencesData.length; i++) {
	const element = experiencesData[i];
	renderExperience(element, experiencesElement)
}

function renderExperience(experience, parentElement) {
	const experienceDiv = document.createElement("div")
	experienceDiv.classList.value = "flex flex-col w-full h-72 sm:h-64 bg-secondary border border-highlight rounded-lg p-3 md:p-4 gap-2 group"
	parentElement.appendChild(experienceDiv);

	const smallDurationDiv = document.createElement("div")
	smallDurationDiv.classList.value = "hidden flex-row text-xxs sm:text-xs gap-2"
	smallDurationDiv.append(...durationElement(experience.duration))
	experienceDiv.appendChild(smallDurationDiv)

	const experienceInfoDiv = document.createElement("div")
	experienceInfoDiv.classList.value = "flex flex-row gap-2 sm:gap-4 min-h-1/4"
	experienceDiv.appendChild(experienceInfoDiv);

	const image = document.createElement("img")
	image.classList.value = "aspect-square h-full"
	image.src = `./assets/images/experiences/${experience.image}`
	experienceInfoDiv.appendChild(image);

	const experienceInfoTextDiv = document.createElement("div")
	experienceInfoTextDiv.classList.value = "flex flex-col h-full"
	experienceInfoDiv.appendChild(experienceInfoTextDiv)

	const normalDurationDiv = document.createElement("div")
	normalDurationDiv.classList.value = "flex flex-row text-xxs sm:text-xs gap-2"
	normalDurationDiv.append(...durationElement(experience.duration))

	const positionName = document.createElement("h1")
	positionName.classList.value = "text-md sm:text-lg md:text-2xl"
	positionName.innerHTML = experience.name

	const companyLink = document.createElement("a")
	companyLink.classList.value = "flex"
	if (experience.company.link)
	{
		companyLink.href = experience.company.link
		companyLink.target = "_blank"
	}
	const companyName = document.createElement("h2")
	companyName.classList.value = `text-xs sm:text-lg text-[${experience.color}]`
	companyName.innerHTML = experience.company.name
	companyLink.appendChild(companyName)
	experienceInfoTextDiv.append(normalDurationDiv, positionName, companyLink)

	const smallCompanyLink = companyLink.cloneNode(true)
	smallCompanyLink.classList.value = "hidden"
	experienceDiv.appendChild(smallCompanyLink)

	const description = document.createElement("p")
	description.classList.value = "sflex text-lightText text-sm h-full"
	description.innerHTML = experience.description
	experienceDiv.appendChild(description)

	const experienceDetailsDiv = document.createElement("div")
	experienceDetailsDiv.classList.value = "flex flex-row items-end h-fit w-full"
	experienceDiv.appendChild(experienceDetailsDiv);

	const detailsRow = document.createElement("div")
	detailsRow.classList.value = "flex flex-row items-center gap-2 sm:gap-4 w-full"
	experienceDetailsDiv.appendChild(detailsRow)

	detailsRow.append(smallText(experience.details.office), dot(experience.color), smallText(experience.details.type), dot(experience.color), smallText(experience.details.location))

	if (experience.company.link)
	{
		const linkIcon = document.createElement("a")
		linkIcon.href = experience.company.link
		linkIcon.target = "blank_"
		linkIcon.classList.value = "lg:hidden lg:group-hover:flex h-full justify-end items-center hover:opacity-70 ease-in-out duration-300"
		experienceDetailsDiv.appendChild(linkIcon)

		const linkIconImg = document.createElement("img")
		linkIconImg.classList.value = "flex h-full"
		linkIconImg.src = "./assets/images/link.svg"
		linkIcon.appendChild(linkIconImg)
	}

	const lineElement = document.createElement("div")
	lineElement.classList.value = "h-4 sm:h-8 w-[1px] bg-highlight"
	parentElement.appendChild(lineElement)
}

function durationElement(duration) {
	const durationFrom = document.createElement("p")
	durationFrom.classList.value = "text-lightText"
	durationFrom.innerHTML = duration.from

	const dash = document.createElement("p")
	dash.classList.value = "text-lightText"
	dash.innerHTML = "-"

	const durationTo = document.createElement("p")
	durationTo.classList.value = "text-lightText"
	durationTo.innerHTML = duration.to
	return ([durationFrom, dash, durationTo])
}

function smallText(text) {
	const element = document.createElement("div")
	element.classList.value = "text-xxs sm:text-xs md:text-sm"
	element.innerHTML = text
	return (element)
}

function dot(color) {
	const element = document.createElement("div")
	element.classList.value = `bg-[${color}] w-[5px] h-[5px] rounded-full`
	return (element)
}
