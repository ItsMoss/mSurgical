from random import seed, choice, randint

def main():
	# list of surgeries available to be generated
	surgeries = ["Ablation",
				 "Angioplasty",
				 "Appendectomy",
				 "Bone repair",
				 "Breast biopsy",
				 "Bronchoscopy",
				 "Carotid endarterectomy",
				 "Carpal tunnel release",
				 "Cataract surgery",
				 "C section",
				 "Cholecystectomy",
				 "Colonoscopy",
				 "Coronary artery bypass",
				 "Debridement",
				 "D&C",
				 "Endoscopy of intestines",
				 "ERCP",
				 "Feducia marking",
				 "Free skin graft",
				 "Heart Valve Removal",
				 "Hemorrhoidectomy",
				 "Hip replacement",
				 "Hysterectomy",
				 "Hysteroscopy",
				 "Inguinal hernia repair",
				 "Knee replacement",
				 "Liposuction",
				 "Low back pain surgery",
				 "Lumbar puncture",
				 "Mastectomy",
				 "Partial colectomy",
				 "Polysomnogram",
				 "Prostatectomy",
				 "Rhinoplasty",
				 "Shoulder replacement",
				 "Small bowel resection",
				 "Soft tissue repair",
				 "Spinal fusion",
				 "Thoracentesis",
				 "Tonsillectomy"]

	# choose a surgery and create 2-toolID sequence at random
	seed();
	surgery2generate = choice(surgeries);
	toolId1 = randint(0, 3);
	toolId2 = randint(0, 3);

	# generate file
	filename = ".\\surgicalfiles\\" + surgery2generate + ".surgery";
	with open(filename, "w+") as f:
		f.write(str(toolId1));
		f.write("\n");
		f.write(str(toolId2));
		f.write("\n");


if __name__ == "__main__":
	main();
