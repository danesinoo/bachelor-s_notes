import os
import shutil

def rename_and_move_pdfs(source_directory, destination_directory):
    # Ensure the destination directory exists
    os.makedirs(destination_directory, exist_ok=True)

    # Iterate through each folder in the source directory
    for folder_name in os.listdir(source_directory):
        folder_path = os.path.join(source_directory, folder_name)
        
        # Check if it is a directory
        if os.path.isdir(folder_path):
            pdf_path = os.path.join(folder_path, 'main.pdf')
            
            # Check if the main.pdf file exists in the folder
            if os.path.isfile(pdf_path):
                new_pdf_name = f"{folder_name}.pdf"
                new_pdf_path = os.path.join(destination_directory, new_pdf_name)
                
                # Move and rename the PDF file
                shutil.move(pdf_path, new_pdf_path)
                print(f"Moved {pdf_path} to {new_pdf_path}")

# Usage
source_directory = './'
destination_directory = './pdfs/'

rename_and_move_pdfs(source_directory, destination_directory)
