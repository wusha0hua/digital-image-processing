function varargout = ImageProcessingGUIdemo(varargin)
% IMAGEPROCESSINGGUIDEMO M-file for ImageProcessingGUIdemo.fig
%      IMAGEPROCESSINGGUIDEMO, by itself, creates a new IMAGEPROCESSINGGUIDEMO or raises the existing
%      singleton*.
%
%      H = IMAGEPROCESSINGGUIDEMO returns the handle to a new IMAGEPROCESSINGGUIDEMO or the handle to
%      the existing singleton*.
%
%      IMAGEPROCESSINGGUIDEMO('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in IMAGEPROCESSINGGUIDEMO.M with the given input arguments.
%
%      IMAGEPROCESSINGGUIDEMO('Property','Value',...) creates a new IMAGEPROCESSINGGUIDEMO or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before ImageProcessingGUIdemo_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to ImageProcessingGUIdemo_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help ImageProcessingGUIdemo

% Last Modified by GUIDE v2.5 10-Nov-2015 15:32:52

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @ImageProcessingGUIdemo_OpeningFcn, ...
                   'gui_OutputFcn',  @ImageProcessingGUIdemo_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before ImageProcessingGUIdemo is made visible.
function ImageProcessingGUIdemo_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to ImageProcessingGUIdemo (see VARARGIN)

home;
warning('off', 'all');

movegui(handles.figure_main, 'center');

javaFrame = get(hObject, 'JavaFrame');
javaFrame.setFigureIcon(javax.swing.ImageIcon('uestc.png'));

handle_splash = splash('电子科技大学.png'); 

global MyStr;
MyStr = '基于GUI的图像处理示例程序_版权所有_电子科技大学航空航天学院_王登位_';
handles.timer = timer('Period', 0.5, 'ExecutionMode', 'FixedRate', 'TimerFcn', {@timercallback, handles});
start(handles.timer);

handles.ListboxCounter = 1;

% Choose default command line output for ImageProcessingGUIdemo
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes ImageProcessingGUIdemo wait for user response (see UIRESUME)
% uiwait(handles.figure_main);


% --- Outputs from this function are returned to the command line.
function varargout = ImageProcessingGUIdemo_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
if ~isempty(handles)
    varargout{1} = handles.output;
    %最大化显示控制模块
    javaFrame = get(handles.figure_main, 'JavaFrame');
    set(javaFrame, 'Maximized', 0);
    
    %去除工具栏与下方区域之间的分割条
    javaFrame.showTopSeparator(false);
    
    %改变工具栏的背景颜色
    jTbar = get(get(findall(handles.figure_main, 'Tag', 'my_uitoolbar'), 'JavaContainer'), 'ComponentPeer');
    color = java.awt.Color.green;
    jTbar.setBackground(color); 
else
    return;
end


% --- Executes on selection change in listbox_InfomationOutput.
function listbox_InfomationOutput_Callback(hObject, eventdata, handles)
% hObject    handle to listbox_InfomationOutput (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns listbox_InfomationOutput contents as cell array
%        contents{get(hObject,'Value')} returns selected item from listbox_InfomationOutput


% --- Executes during object creation, after setting all properties.
function listbox_InfomationOutput_CreateFcn(hObject, eventdata, handles)
% hObject    handle to listbox_InfomationOutput (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in popupmenu_FilteringMethod.
function popupmenu_FilteringMethod_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu_FilteringMethod (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu_FilteringMethod contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu_FilteringMethod
switch get(hObject, 'Value');
    case 1
        handles.FilterMethod = '';
    case 2
        handles.FilterMethod = '中值滤波';
    case 3
        handles.FilterMethod = '均值滤波';
    case 4
        handles.FilterMethod = '高斯滤波';
    otherwise     
end
if handles.OutputInformationFlag
    set(handles.listbox_InfomationOutput, 'String', strvcat(get(handles.listbox_InfomationOutput, 'String'), ['当前的边缘滤波方法为：', handles.FilterMethod]));
    set(handles.listbox_InfomationOutput, 'ListboxTop', handles.ListboxCounter);
    handles.ListboxCounter = handles.ListboxCounter + 1;
end
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function popupmenu_FilteringMethod_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu_FilteringMethod (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
set(hObject, 'Value', 1);
handles.FilterMethod = '';
guidata(hObject, handles);


function edit_InputImage_Callback(hObject, eventdata, handles)
% hObject    handle to edit_InputImage (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_InputImage as text
%        str2double(get(hObject,'String')) returns contents of edit_InputImage as a double


% --- Executes during object creation, after setting all properties.
function edit_InputImage_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_InputImage (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton_InputImage.
function pushbutton_InputImage_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_InputImage (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[FileName, PathName, FilterIndex] = uigetfile('./image/*.*', '导入待处理图像');
if FilterIndex == 0
    retuen;
end
set(handles.edit_InputImage, 'String', [PathName, FileName]);
handles.InputImage = imread([PathName, FileName]);
if ndims(handles.InputImage) == 3
    handles.InputImage = rgb2gray(handles.InputImage);
end
if handles.OutputInformationFlag
    set(handles.listbox_InfomationOutput, 'String', strvcat(get(handles.listbox_InfomationOutput, 'String'), ['当前图像所在路径为：', fullfile(PathName, FileName)]));
    set(handles.listbox_InfomationOutput, 'ListboxTop', handles.ListboxCounter);
    handles.ListboxCounter = handles.ListboxCounter + 1;
end
imshow(handles.InputImage, 'Parent', handles.axes_OriginalImage, 'DisplayRange', []);
guidata(hObject, handles);


% --- Executes on button press in checkbox_OutputInformation.
function checkbox_OutputInformation_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox_OutputInformation (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox_OutputInformation
checkBox = get(hObject, 'Value');
if checkBox
    handles.OutputInformationFlag = 1;
else
    handles.OutputInformationFlag = 0;
end
guidata(hObject, handles);

% --- Executes on slider movement.
function slider_PreviewImage_Callback(hObject, eventdata, handles)
% hObject    handle to slider_PreviewImage (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider
sliderValue = round(get(hObject, 'Value'));
set(handles.static_text_PreviewImage, 'String', num2str(sliderValue));
imshow(handles.ImageSequence{sliderValue}, 'DisplayRange', [], 'Parent',handles.axes_SliderPreview);


% --- Executes during object creation, after setting all properties.
function slider_PreviewImage_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider_PreviewImage (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end
set(hObject, 'Enable', 'off');


% --- Executes during object creation, after setting all properties.
function uitable_GrayComatrixResult_CreateFcn(hObject, eventdata, handles)
% hObject    handle to uitable_GrayComatrixResult (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
set(hObject, 'ColumnName', {'FileName'; 'Contrast'; 'Correlation'; 'Energy'; 'Homogeneity'}, 'FontSize', 11, 'ColumnWidth', {100, 100, 100, 100, 100});


% --- Executes on button press in pushbutton_ComputeGrayComatrix.
function pushbutton_ComputeGrayComatrix_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_ComputeGrayComatrix (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
path = './image/滑动条及表格/';
image_index = dir(fullfile(path, '*.jpg'));
count = 0;
for j = 1 : length(image_index)
    count = count + 1;
    FileName{count} = image_index(j).name;
    CurrentImage = imread([path, image_index(j).name]);
    if ndims(CurrentImage) == 3
        CurrentImage = rgb2gray(CurrentImage);
    end
    Comatrix{count} = graycomatrix(CurrentImage, 'Offset', [2, 0]);
    Feature{count} = graycoprops(Comatrix{count});
end
Array = [];
for k = 1 : count
    temp{k} = {FileName{k}, Feature{k}.Contrast, Feature{k}.Correlation, Feature{k}.Energy, Feature{k}.Homogeneity};
    Array = [Array; temp{k}];
end
set(handles.uitable_GrayComatrixResult, 'data', Array, 'ForegroundColor', 'b');


% function edit_PreviewImage_Callback(hObject, eventdata, handles)
% % hObject    handle to edit_PreviewImage (see GCBO)
% % eventdata  reserved - to be defined in a future version of MATLAB
% % handles    structure with handles and user data (see GUIDATA)
% 
% % Hints: get(hObject,'String') returns contents of edit_PreviewImage as text
% %        str2double(get(hObject,'String')) returns contents of edit_PreviewImage as a double
% sliderValue = get(handles.edit_PreviewImage, 'String');
% sliderValue = str2num(sliderValue);
% if (isempty(sliderValue) || sliderValue < 1 || sliderValue > length(handles.ImageSequence))
%     set(handles.slider_PreviewImage, 'Value', 1);
%     set(handles.edit_PreviewImage, 'String', '1');
% else
%     set(handles.slider_PreviewImage, 'Value', sliderValue);
% end
% 
% 
% % --- Executes during object creation, after setting all properties.
% function edit_PreviewImage_CreateFcn(hObject, eventdata, handles)
% % hObject    handle to edit_PreviewImage (see GCBO)
% % eventdata  reserved - to be defined in a future version of MATLAB
% % handles    empty - handles not created until after all CreateFcns called
% 
% % Hint: edit controls usually have a white background on Windows.
% %       See ISPC and COMPUTER.
% if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
%     set(hObject,'BackgroundColor','white');
% end
% set(hObject, 'Enable', 'off');


function timercallback(obj, event, handles)
global MyStr;
Str1 = MyStr(1);
Str2 = MyStr(2 : end);
MyStr = strcat(Str2, Str1);
set(handles.figure_main, 'Name', MyStr);



function edit_AverageRow_Callback(hObject, eventdata, handles)
% hObject    handle to edit_AverageRow (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_AverageRow as text
%        str2double(get(hObject,'String')) returns contents of edit_AverageRow as a double
handles.AverageFilterRow = round(str2double(get(hObject, 'String')));
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function edit_AverageRow_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_AverageRow (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
set(hObject, 'String', num2str(5));
handles.AverageFilterRow = round(str2double(get(hObject, 'String')));
guidata(hObject, handles);


function edit_AverageCol_Callback(hObject, eventdata, handles)
% hObject    handle to edit_AverageCol (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_AverageCol as text
%        str2double(get(hObject,'String')) returns contents of edit_AverageCol as a double
handles.AverageFilterCol = round(str2double(get(hObject, 'String')));
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function edit_AverageCol_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_AverageCol (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
set(hObject, 'String', num2str(5));
handles.AverageFilterCol = round(str2double(get(hObject, 'String')));
guidata(hObject, handles);


function edit_GaussianRow_Callback(hObject, eventdata, handles)
% hObject    handle to edit_GaussianRow (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_GaussianRow as text
%        str2double(get(hObject,'String')) returns contents of edit_GaussianRow as a double
handles.GaussianFilterRow = round(str2double(get(hObject, 'String')));
guidata(hObject, handles); 


% --- Executes during object creation, after setting all properties.
function edit_GaussianRow_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_GaussianRow (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
set(hObject, 'String', num2str(5));
handles.GaussianFilterRow = round(str2double(get(hObject, 'String')));
guidata(hObject, handles); 


function edit_GaussianCol_Callback(hObject, eventdata, handles)
% hObject    handle to edit_GaussianCol (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_GaussianCol as text
%        str2double(get(hObject,'String')) returns contents of edit_GaussianCol as a double
handles.GaussianFilterCol = round(str2double(get(hObject, 'String')));
guidata(hObject, handles); 


% --- Executes during object creation, after setting all properties.
function edit_GaussianCol_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_GaussianCol (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
set(hObject, 'String', num2str(5));
handles.GaussianFilterCol = round(str2double(get(hObject, 'String')));
guidata(hObject, handles); 


function edit_GaussianSigma_Callback(hObject, eventdata, handles)
% hObject    handle to edit_GaussianSigma (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_GaussianSigma as text
%        str2double(get(hObject,'String')) returns contents of edit_GaussianSigma as a double
handles.GaussianFilterSigma = round(str2double(get(hObject, 'String')));
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function edit_GaussianSigma_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_GaussianSigma (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
set(hObject, 'String', num2str(0.9));
handles.GaussianFilterSigma = round(str2double(get(hObject, 'String')));
guidata(hObject, handles);


function edit_MedianRow_Callback(hObject, eventdata, handles)
% hObject    handle to edit_MedianRow (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_MedianRow as text
%        str2double(get(hObject,'String')) returns contents of edit_MedianRow as a double
handles.MedianFilterRow = round(str2double(get(hObject, 'String')));
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function edit_MedianRow_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_MedianRow (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
set(hObject, 'String', num2str(5));
handles.MedianFilterRow = round(str2double(get(hObject, 'String')));
guidata(hObject, handles);


function edit_MedianCol_Callback(hObject, eventdata, handles)
% hObject    handle to edit_MedianCol (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_MedianCol as text
%        str2double(get(hObject,'String')) returns contents of edit_MedianCol as a double
handles.MedianFilterCol = round(str2double(get(hObject, 'String')));
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function edit_MedianCol_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_MedianCol (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
set(hObject, 'String', num2str(5));
handles.MedianFilterCol = round(str2double(get(hObject, 'String')));
guidata(hObject, handles);


% --- Executes when selected object is changed in uipanel_EdgeDetector.
function uipanel_EdgeDetector_SelectionChangeFcn(hObject, eventdata, handles)
% hObject    handle to the selected object in uipanel_EdgeDetector 
% eventdata  structure with the following fields (see UIBUTTONGROUP)
%	EventName: string 'SelectionChanged' (read only)
%	OldValue: handle of the previously selected object or empty if none was selected
%	NewValue: handle of the currently selected object
% handles    structure with handles and user data (see GUIDATA)
str = get(hObject, 'string');
switch str
    case 'Canny'
        handles.edge_detector = 'Canny';
    case 'Sobel'
        handles.edge_detector = 'Sobel';
    case 'Prewitt'
        handles.edge_detector = 'Prewitt';
    otherwise
end
if handles.OutputInformationFlag
    set(handles.listbox_InfomationOutput, 'String', strvcat(get(handles.listbox_InfomationOutput, 'String'), ['当前的边缘检测算子为：', str]));
    set(handles.listbox_InfomationOutput, 'ListboxTop', handles.ListboxCounter);
    handles.ListboxCounter = handles.ListboxCounter + 1;
end
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function uipanel_EdgeDetector_CreateFcn(hObject, eventdata, handles)
% hObject    handle to uipanel_EdgeDetector (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
handles.edge_detector = 'Canny';
guidata(hObject, handles);


% --- Executes on button press in pushbutton_Photoshop.
function pushbutton_Photoshop_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_Photoshop (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
open('D:\Program Files\Photoshop CS6\Adobe Photoshop CS6 (64 Bit)\Photoshop.exe');


% --- Executes on button press in pushbutton_ImageSequence.
function pushbutton_ImageSequence_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_ImageSequence (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.preview_folder_name = uigetdir('./image/', '导入预览序列所在文件夹');
if handles.preview_folder_name == 0
    return;
end
set(handles.slider_PreviewImage, 'Enable', 'on');
set(handles.static_text_PreviewImage, 'Enable', 'on');
image_index = dir(fullfile(handles.preview_folder_name, '\', '*.jpg'));
imshow(imread([handles.preview_folder_name, '\', image_index(1).name]), 'Parent', handles.axes_SliderPreview);
for i = 1 : length(image_index)
    handles.ImageSequence{i} = imread([handles.preview_folder_name, '\', image_index(i).name]);
end
set(handles.slider_PreviewImage, 'Min', 1);
set(handles.slider_PreviewImage, 'Max', length(handles.ImageSequence));
set(handles.slider_PreviewImage, 'Value', 1);
set(handles.static_text_PreviewImage, 'String', num2str(1));
stepSize(1) = 1 / length(handles.ImageSequence);
stepSize(2) = 1 / length(handles.ImageSequence) * 2;
set(handles.slider_PreviewImage, 'sliderstep', stepSize);
guidata(hObject, handles);


% --- Executes when user attempts to close figure_main.
function figure_main_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figure_main (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: delete(hObject) closes the figure
stop(handles.timer);
delete(hObject);


% --- Executes on button press in pushbutton_start.
function pushbutton_start_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_start (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if isfield(handles, 'InputImage')
    %滤波
    switch handles.FilterMethod
        case '中值滤波'
            DenoisedImage = medfilt2(handles.InputImage, [handles.MedianFilterRow, handles.MedianFilterCol]);
        case '均值滤波'
            Filter = fspecial('average', [handles.AverageFilterRow, handles.AverageFilterCol]);
            DenoisedImage = imfilter(handles.InputImage, Filter, 'replicate', 'same', 'conv');
        case '高斯滤波'
            Filter = fspecial('gaussian', [handles.GaussianFilterRow, handles.GaussianFilterCol], handles.GaussianFilterSigma);
            DenoisedImage = imfilter(handles.InputImage, Filter, 'replicate', 'same', 'conv');
        otherwise
            
    end
    %边缘检测
    edge_image = edge(handles.InputImage, handles.edge_detector);
    imshow(edge_image, 'Parent', handles.axes_Result, 'DisplayRange', []);
else
    magbox('请导入图像数据', '错误提示');
    return;
end


% --- Executes during object creation, after setting all properties.
function pushbutton_start_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pushbutton_start (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
set(hObject, 'Units', 'pixels');
button_position = get(hObject, 'Position');
image = imresize(imread('开始处理.png'), [button_position(4), button_position(3)], 'bicubic');
set(hObject, 'CData', image);


% --- Executes during object creation, after setting all properties.
function checkbox_OutputInformation_CreateFcn(hObject, eventdata, handles)
% hObject    handle to checkbox_OutputInformation (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
set(hObject, 'Value', 1);
handles.OutputInformationFlag = get(hObject, 'Value');
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function static_text_PreviewImage_CreateFcn(hObject, eventdata, handles)
% hObject    handle to static_text_PreviewImage (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
set(hObject, 'Enable', 'off');


% --------------------------------------------------------------------
function copyright_page_Callback(hObject, eventdata, handles)
% hObject    handle to copyright_page (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
eval('image_and_text_caption');


% --------------------------------------------------------------------
function developer_Callback(hObject, eventdata, handles)
% hObject    handle to developer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
eval('HyperlinkGUIDemo');


% --------------------------------------------------------------------
function uitoggletool_help_ClickedCallback(hObject, eventdata, handles)
% hObject    handle to uitoggletool_help (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
winopen('基于GUI的图像处理案例使用说明.chm');
