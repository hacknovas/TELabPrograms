from nltk.chat.util import Chat,reflections

reflections={
"i am":"you are",
"my":"your"
}

chats=[
    [
        r"who are (.*)",
        ["Doni","Mahi"]
    ]
]

def chat():
    print("Doni Prathamesh")
    chat=Chat(chats,reflections)
    chat.converse()


if __name__=="__main__":
    chat()