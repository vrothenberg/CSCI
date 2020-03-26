#Shane Roush#
#11-29-19#
#CSCI 4 Final Project#


import random#import random#
import time
from random import shuffle#import shuffle from random#

class Question:#create class self for answers and prompts#
    def __init__(self, prompt, answer):
          self.prompt = prompt
          self.answer = answer
          
#random.choice(question_prompts)
random.seed(time.time())

question_prompts = [#list of Questions and prompts#
#1
     " Harmful programs used to disrupt computer operation, gather sensitive information, or gain unauthorized access to computer systems are commonly referred to as:"
     "\n(a) Adware\n(b) Malware\n(c) Ransomware\n(d) Spyware",
#2     
     " Which of the terms listed below refers to an example of a crypto-malware?"
     "\n(a) Backdoor\n(b) Ransomware\n(c) Keylogger\n(d) Rootkit",
#3    
     " Which of the following statements apply to the definition of a computer virus? (Select 3 answers):"
     "\n(a) A self-replicating computer program containing malicious segment\n(b) Requires its host application to be run to make the virus active."
     "\n(c) A standalone malicious computer program that replicates itself over a computer network."
     "\n(d) Can run by itself without any interaction."
     "\n(e) Attaches itself to an application program or other executable component."
     "\n(f) A self-contained malicious program or code that does need a host to propagate itself.",
#4     
     "Malware that restricts access to a computer system by encrypting files or locking the entire system down until the user performs requested action is known as:"
     "\n(a) Grayware\n(b) Adware\n(c) Ransomware\n(d) Spyware",
#5
     " A standalone malicious computer program that typically propagates itself over a computer network to adversely affect system resources and network bandwidth is called:"
     "\n(a) Spyware\n(b) Worm \n(c) Trojan\n(d) Spam",
#6     
     " True of False?"
     " A type of software that performs unwanted and harmful actions in disguise of a legitimate and useful program is known as a Trojan horse. This type of malware may act like"
     "a legitimate program and have all the expected functionalities, but apart from that it will also contain a portion of malicious code that the user is unaware of."
     "\n(a) True\n(b) False",
#7
     "A collection of software tools used by a hacker to mask intrusion and obtain administrator-level access to a computer or computer network is known as:"
     "\n(a) Rootkit\n(b) Spyware\n(c) Backdoor\n(d) Trojan",
#8
     "Which of the following answers lists an example of spyware?"
     "\n(a) Keylogger\n(b) Vulnerability scanner\n(c) Computer worm\n(d) Packet sniffer",

#9
     "What is adware?"
     "\n(a) Unsolicited or undesired electronic messages\n(b) Malicious program that sends copies of itself to other computers on the network"
     "\n(c) Software that displays advertisements\n(d) Malicious software that collects information about users without their knowledge",
#10
     "Malicious software collecting information about users without their knowledge or consent is known as:"
     "\n(a) Crypto malware\n(b) Adware\n(c) Ransomware\n(d) Spyware",
#11
     "A malware-infected networked host under remote control of a hacker is commonly referred to as:"
     "\n(a) Trojan\n(b) Worm\n(c) Bot\n(d) Honeypot",
#12
     "Which of the terms listed below applies to a collection of intermediary compromised systems that are used as a platform for a DDoS attack?"
     "\n(a) Honeynet\n(b) Botnet\n(c) Quarantine network\n(d) Malware",
#13
     "Which type of Trojan enables unauthorized remote access to a compromised system?"
     "\n(a) pcap\n(b) RAT\n(c) MaaS\n(d) pfSense",
#14
     "Malicious code activated by a specific event is called:"
     "\n(a) Backdoor\n(b) Logic bomb\n(c) Dropper\n(d) Retrovirus",
#15
     "Which of the following answers refers to an undocumented (and often legitimate) way of gaining access to a program, online service, or an entire computer system?"
     "\n(a) Logic bomb\n(b) Trojan horse\n(c) Rootkit\n(d) Backdoor",
#16
     "An unauthorized practice of obtaining confidential information by manipulating people into disclosing sensitive data is referred to as:"
     "\n(a) Shoulder surfing\n(b) Privilege escalation\n(c) Social engineering\n(d) Penetration testing",
#17
     "A fraudulent email requesting its recipient to reveal sensitive information (e.g. username and password) used later by an attacker for the purpose"
     "of identity theft is an example of: (Select all that apply)"
     "\n(a) Phishing\n(b) Watering hole attack\n(c) Social engineering\n(d) Bluejacking\n(e) Vishing",
#18
     "A social engineering technique whereby attackers under disguise of a legitimate request attempt to gain access to confidential information"
     "they shouldn't have access to is commonly referred to as:"
     "\n(a) Phishing\n(b) Privilege escalation\n(c) Backdoor access\n(d) Shoulder surfing",
#19
     "Phishing scams targeting a specific group of people are referred to as:"
     "\n(a) Vishing\n(b) Spear phishing\n(c) Spoofing\n(d) Whaling",
#20
     "Phishing scams targeting people holding high positions in an organization or business are known as:"
     "\n(a) Vishing\n(b) Bluesnarfing\n(c) Whaling\n(d) Bluejacking\n(e) Pharming",
#21
     "The practice of using a telephone system to manipulate user into disclosing confidential information is called:"
     "\n(a) Whaling\n(b) Spear phishing\n(c) Vishing \n(d) Pharming",
#22
     "What is tailgating?"
     "\n(a) Acquiring unauthorized access to confidential data\n(b) Looking over someone's shoulder to get information\n(c)"
     "Gaining unauthorized access to restricted areas by following another person\n(d) Manipulating a user into disclosing confidential information",
#23
     "Which social engineering attack relies on identity theft?"
     "\n(a) Impersonation\n(b) Dumpster diving\n(c) Watering hole attack\n(d) Shoulder surfing",
#24
     "True or False?"
     " In computer security, the term ""Dumpster diving"" is used to describe a practice of sifting through trash for discarded documents containing"
     "sensitive data. Found documents containing names and surnames of the employees along with the information about positions held in the company"
     "and other data can be used to facilitate social engineering attacks. Having the documents shredded or incinerated before disposal makes dumpster"
     "diving less effective and mitigates the risk of social engineering attacks."
     "\n(a) True\n(b) False",
#25
     "A situation in which an unauthorized person can view another user's display or keyboard to learn their password or other confidential information is referred to as:"
     "\n(a) Spear phishing\n(b) Tailgating\n(c) Shoulder surfing\n(d) Spoofing"]



questions = [#answers to questions#
     Question(question_prompts[0], "b"),
     Question(question_prompts[1], "b"),
     Question(question_prompts[2], "abe"),
     Question(question_prompts[3], "c"),
     Question(question_prompts[4], "b"),
     Question(question_prompts[5], "a"),
     Question(question_prompts[6], "a"),
     Question(question_prompts[7], "a"),
     Question(question_prompts[8], "c"),
     Question(question_prompts[9], "d"),
     Question(question_prompts[10], "c"),
     Question(question_prompts[11], "b"),
     Question(question_prompts[12], "b"),
     Question(question_prompts[13], "b"),
     Question(question_prompts[14], "d"),
     Question(question_prompts[15], "c"),
     Question(question_prompts[16], "ac"),
     Question(question_prompts[17], "a"),
     Question(question_prompts[18], "b"),
     Question(question_prompts[19], "c"),
     Question(question_prompts[20], "c"),
     Question(question_prompts[21], "c"),
     Question(question_prompts[22], "a"),
     Question(question_prompts[23], "a"),
     Question(question_prompts[24], "c"),
     
     
    ]

random.Random(time.time()).shuffle(questions)#shuffle questions#


def runExam(questions):#defined runExam  using loop
     score = 0
     for question in questions:
          answer = input(question.prompt)
          if answer == question.answer:
              print("CORRECT!")
              score += 1
          else:
              print("INCORRECT!")
     print("you got", score, "out of", len(questions))

runExam(questions)#end runExam()#
