//
// Created by ahmad on 4/17/19.
//


#include "FillHoleCommand.h"


enum cmd {
    COMMAND, IMAGE_PATH, MASK, OUTPUT_PATH, EPSILON, Z_VALUE, CONNECTIVITY_TYPE
};

CommandB::CommandB(const std::string &name) : m_name(name), m_command_line_words(7) {}

//  this function returns the specification of the command, static member
//  function to prevent creating new one on every function call
const std::string &CommandB::getCommandSpecification(const std::string &my_connectivity) {
    const static std::string specification =
            "<image_path> <mask_path> <output_path> <epsilon> <z_value>" + my_connectivity;
    return specification;
}

void CommandB::runCommand(const std::vector<std::string> &v_cmd, const ConnectivityStore &c_s) {

    ExceptionValidator::validateInputCount(v_cmd.size(), m_command_line_words);
    cv::Mat image = ImageUtil::combineTwoImages(v_cmd[IMAGE_PATH].c_str(), v_cmd[MASK].c_str());


    float e = 0, z = 0;
    try {
        e = ExceptionValidator::validateStringIsFloat(v_cmd[EPSILON]);
    } catch (std::invalid_argument &e) {
        throw std::invalid_argument("epsilon is not a valid number");
    }
    try {
        z = ExceptionValidator::validateStringIsFloat(v_cmd[Z_VALUE]);
    } catch (std::invalid_argument &e) {
        throw std::invalid_argument("z is not a valid number");
    }

    IPixelConnectivity_ptr connectivity(c_s.getConnectivity(v_cmd[CONNECTIVITY_TYPE]));
    image = HoleFillerLib::Algorithms::fillHoleAlgo(image, connectivity, e, z, -1);
    ImageUtil::saveImage(image, v_cmd[OUTPUT_PATH]);

}


