from PIL import Image, ImageFilter

before = Image.open("filter/images/courtyard.bmp")
after = before.filter(ImageFilter.BLUR)
after.save("out.bmp")